#!/usr/bin/env python

import lib.doc as doc
import lib.cudaToolkit91.cuda as spec
import pprint
import sys
import os
import io
from string import Template
import clang.cindex

def get_min_uint( val ):
  uint_type = [ "uint8_t", "uint16_t", "uint32_t", "uint64_t" ][ val // 16 ]
  val_ext = [ "", "u", "ul", "ull" ][ val // 16 ]
  return [ uint_type, val_ext ]

# poor man's indenting
def fix_indent( m ):
  out = ""
  level = 0
  for line in m.split("\n"):
    next_level = level
    last_char = '{'
    for i in range(len(line)):
      if line[i] == '}':
        next_level -= 1
        last_char = line[i]
      elif line[i] == '{':
        next_level += 1
        last_char = line[i]

    for i in range( next_level if last_char == '}' else level):
      out += "  "
    out += line.strip() + "\n"

    level = next_level
  return out

def get_ptype_pname( parm ):
  # 'size_t' needs to be patched :-(
  pspell = parm.header.spelling
  try:
    ptype = parm.manual.typepatch
  except:
    if parm.header.type.kind == clang.cindex.TypeKind.INCOMPLETEARRAY:
      ptype = parm.header.type.spelling[:-2] # instead of []
      pspell += " []"
    elif parm.header.type.kind == clang.cindex.TypeKind.TYPEDEF:
      ptype = parm.header.type.get_typedef_name()
    else:
      ptype = parm.header.type.spelling
  return (ptype, pspell)
  
def get_pointee_ptype( parm ):
   # currently used in cases of 'size_t' .. ugly
  try:
    ptype = parm.manual.typepatch
    ptype = ptype[:ptype.rfind('*')-1] # need pointee
  except:
    if parm.header.type.kind == clang.cindex.TypeKind.INCOMPLETEARRAY:
      ptype = parm.header.type.spelling[:-2].strip() # removes the []
    else:
      pointee = parm.header.type.get_pointee()
      if pointee.kind == clang.cindex.TypeKind.TYPEDEF:
        ptype = pointee.get_typedef_name()
      else:
        ptype = pointee.spelling
      if pointee.is_const_qualified(): 
        ptype = ptype.replace("const", "").strip()
  return ptype

def isPointerOrArray( kind ):
  return (kind == clang.cindex.TypeKind.POINTER
          or kind == clang.cindex.TypeKind.INCOMPLETEARRAY)
  

def gen_struct(variables, packed=False):
  if len(variables) == 0:
    return ""

  tstruct = Template("""struct${STRUCT_PACKED} {
                            ${STRUCT_VARS}
                        }""")
  tstruct_f = { "STRUCT_VARS" : "\n".join( "%s %s;" % (v[0], v[1]) for v in variables),
                "STRUCT_PACKED" : " __attribute__((packed))" if packed else "" }
  st = tstruct.substitute(tstruct_f)
  return st

def gen_assign(name, assignment):
  if assignment == None or assignment == []:
    return []

  asg = []
  if assignment:
    asg = [ Template(a).substitute( { "STRUCT" : name } ) for a in assignment ]
  return asg

def gen_send_func( struct_ptr, struct_len ):
  snd_struct = Template("""hfcheck( hfcuda_comm_send( ${STRUCT_PTR}, ${STRUCT_LEN} ));
                           """)
  fl = { "STRUCT_PTR" : struct_ptr,
         "STRUCT_LEN" : struct_len }
  return snd_struct.substitute( fl )

def gen_recv_struct( struct, struct_ptr, struct_len ):
  rcv_struct = Template("""${STRUCT}
                           hfcheck( hfcuda_comm_recv( ${STRUCT_PTR}, ${STRUCT_LEN} ));
                           """)
  fl = { "STRUCT" : struct,
         "STRUCT_PTR" : struct_ptr,
         "STRUCT_LEN" : struct_len }
  return rcv_struct.substitute( fl )


 
#############################################
#############################################
#############################################


def cudaDataType_parm_val_size( varname ):
  parm_type = "char"
  parm_val = "%s[sizeof(uint64_t) * 2] /* support for 64bit complex */" % varname
  parm_val_size = "sizeof(uint64_t) * 2"
  return ( parm_type, parm_val, parm_val_size )

def cudaDataType_assign( cudaDataTypeCase, to_ptr, from_ptr ):
  tmpl = """switch( ${CASE} ) {
            case CUDA_R_8I: 
            case CUDA_R_8U: {  // 8bit real
              *(uint8_t*)${TOPTR} = *(uint8_t*)${FROMPTR};
              break;
            }
            case CUDA_R_16F:
            case CUDA_C_8I:
            case CUDA_C_8U: {  // 8bit complex / 16bit real
              *(uint16_t*)${TOPTR} = *(uint16_t*)${FROMPTR};
              break;
            }
            case CUDA_C_16F:
            case CUDA_R_32I:
            case CUDA_R_32U:
            case CUDA_R_32F: {  // 16bit complex / 32bit real
              *(uint32_t*)${TOPTR} = *(uint32_t*)${FROMPTR};
              break;
            }
            case CUDA_C_32I:
            case CUDA_C_32F: 
            case CUDA_C_32U:
            case CUDA_R_64F: {  // 32bit complex / 64bit real
              *(uint64_t*)${TOPTR} = *(uint64_t*)${FROMPTR};
              break;
            }
            case CUDA_C_64F: {  // 64bit complex
              *(uint64_t*)${TOPTR} = *(uint64_t*)${FROMPTR};
              *(((uint64_t*)${TOPTR}) + 1) = *(((uint64_t*)${FROMPTR}) + 1);
              break;
            }
            default: {
              hferr("ERR (%s:%s:%s): case not supported! %d\\n", __FILE__, __LINE__, __FUNCTION__, ${CASE});
              exit(-1);
            }
            }"""
  return Template(tmpl).safe_substitute( { "CASE" : cudaDataTypeCase, "TOPTR" : to_ptr, "FROMPTR" : from_ptr } )


# ToDo: optimize for later one! -> currently assume worst case
# 2.7 Tensor Core Operations
# Input, Filter and Output descriptors (xDesc, yDesc, wDesc, dxDesc, dyDesc and dwDesc as applicable) have dataType = CUDNN_DATA_HALF.
def cudnnDataType_parm_val_size( varname, parm ):
  parm_type = "double"
  parm_val = varname
  parm_val_size = "sizeof(double)"
  return ( parm_type, parm_val, parm_val_size )

def cudnnDataType_assign( GLPARMS, descr, to_ptr, from_ptr ):
  GLPARMS['REQ_DEVID'] = True
  tmpl = """cudnnDataType_t ____${DESCR}_dataType;
            hfcheck(hfcuda_get_cudnnDataType( devId, ${DESCR}, &____${DESCR}_dataType ));
            switch( ____${DESCR}_dataType ) {
            case CUDNN_DATA_FLOAT:
            case CUDNN_DATA_HALF: {
              *(float*)${TOPTR} = *(float*)${FROMPTR};
              break;
            }
            case CUDNN_DATA_DOUBLE: {
              *(double*)${TOPTR} = *(double*)${FROMPTR};
              break;
            }
            default: {
              hferr("ERR (%s:%s:%s): case not supported! %d\\n", __FILE__, __LINE__, __FUNCTION__, ____${DESCR}_dataType );
              exit(-1);
            }
            }"""   # half, float -> float, double -> double
  return Template(tmpl).safe_substitute( { "DESCR" : descr, "TOPTR" : to_ptr, "FROMPTR" : from_ptr } )

#############################################
################ T2D VARIABLE TO PARAMETER

def t2d_struct_fncparm( O_PARMDEF, parm ):
  parm_tmpl = "${T2D_STRUCT}.${PARM}"

  fl = { "PARM" : parm.header.spelling }
  O_PARMDEF['D_FUNC_PARM'] = Template(Template( parm_tmpl ).safe_substitute( fl ))

def t2d_struct_fncparm__scalarhostordev_in( O_PARMDEF, parm, pidx ):

  default_parm_tmpl = """(((${T2D_STRUCT}.${BITMAP} >> ${BITMAP_SHIFT}) & 0x1) ? &${T2D_STRUCT}.${PARM_NAME}.val : ${T2D_STRUCT}.${PARM_NAME}.ptr)"""

  pointee = parm.header.type.get_pointee()
  if pointee.kind == clang.cindex.TypeKind.VOID:
    if "cudaDataType" in parm.manual.typedep.header.type.spelling:
      parm_tmpl = """(((${T2D_STRUCT}.${BITMAP} >> ${BITMAP_SHIFT}) & 0x1) ? &${T2D_STRUCT}.${PARM_NAME}.val[0] : ${T2D_STRUCT}.${PARM_NAME}.ptr)"""
    elif "cudnnTensorDescriptor" in parm.manual.typedep.header.type.spelling:
      parm_tmpl = default_parm_tmpl # it only can be double or float
    else:
      print("ToDo: implement t2d_struct_fncparm")
      exit(-1)
  else:
    parm_tmpl = default_parm_tmpl

  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx) }
  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['D_FUNC_PARM'] = Template(Template(parm_tmpl).safe_substitute( fl ))


#############################################
################ D2T VARIABLE TO PARAMETER

def d2t_struct_fncparm_scalarhost( O_PARMDEF, parm ):
  tmpl = "&${D2T_STRUCT}.${PARM_NAME}"

  fl = { "PARM_NAME" : parm.header.spelling }
  O_PARMDEF['D_FUNC_PARM'] = Template(Template(tmpl).safe_substitute( fl ))

def d2t_struct_fncparm__scalarhostordev_out( O_PARMDEF, parm, pidx ):
  reference = "&"
  if parm.manual.type & doc.VECTOR:
    reference = ""
  tmpl = """(((${T2D_STRUCT}.${BITMAP} >> ${BITMAP_SHIFT}) & 0x1) ? """ + reference + """${D2T_STRUCT}.${PARM_NAME} : ${T2D_STRUCT}.${PARM_NAME})"""

  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx) }

  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['D_FUNC_PARM'] = Template(Template(tmpl).safe_substitute( fl ))

def d2t_struct_fncparm__scalarhostordev_inout( O_PARMDEF, parm, pidx ):
  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx) }

  # we have either the choice to check for each parameter if needs to be copied (slow) with above if/else in true case
  # or just copy ... and that's it (fast).
  
  pointee = parm.header.type.get_pointee()
  if pointee.kind == clang.cindex.TypeKind.VOID:
    if "cudaDataType" in parm.manual.typedep.header.type.spelling:
      print("ToDo: use switch/case to copy over!")
      exit(-1)
    else:
      print("ToDo: use switch/case to copy over! (d2t_struct_fncparm)")
      exit(-1)
  else:
    prefunc_tmpl = """${D2T_STRUCT}.${PARM_NAME} = ${T2D_STRUCT}.${PARM_NAME}.val; /* need copy in case host-ptr in & out required! */"""
  O_PARMDEF['D2T_STRUCT_PREFUNC_ASSIGN'] = Template(prefunc_tmpl).safe_substitute( fl )

  # need to copy either the value upfront from t2d into d2t or afterwards if ".val" case is hit!
  tmpl = """(((${T2D_STRUCT}.${BITMAP} >> ${BITMAP_SHIFT}) & 0x1) ? &${D2T_STRUCT}.${PARM_NAME} : ${T2D_STRUCT}.${PARM_NAME}.ptr)"""
  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['D_FUNC_PARM'] = Template(Template(tmpl).safe_substitute( fl ))



#############################################
################ T2D VARIABLE

def t2d_struct_var( O_PARMDEF, parm ):
  ptype, pname = get_ptype_pname( parm )
  # check if a scalar argument is given with const. -> shouldn't be put in struct!
  if parm.header.type.is_const_qualified(): 
    ptype = ptype.replace("const", "").strip()
  if parm.header.type.kind == clang.cindex.TypeKind.INCOMPLETEARRAY:
    pname = pname.replace("[]", "")
    ptype += "*"

  O_PARMDEF['T2D_STRUCT_ARGS'] = [ ptype, pname ]


def t2d_struct_var__scalarhostordev_ptr( O_PARMDEF, parm ):
  parm_val = "val"
  pointee = parm.header.type.get_pointee()
  if pointee.kind == clang.cindex.TypeKind.VOID:
    # need to always assume worst case
    if "cudaDataType" in parm.manual.typedep.header.type.spelling:
      parm_type, parm_val, parm_val_size = cudaDataType_parm_val_size( parm_val )
    elif "cudnnTensorDescriptor" in parm.manual.typedep.header.type.spelling:
      parm_type, parm_val, parm_val_size = cudnnDataType_parm_val_size( parm_val, parm )
    else:
      print("ERR: attempting to put a 'void' as a parameter into the struct '%s'!" % parm.manual.typedep.header.type.spelling )
      exit(-1)

  else:
    ptype = get_pointee_ptype( parm )
  
    parm_type = ptype
    parm_val_size = "sizeof(%s)" % ptype

  p_parmtype = parm.header.type.spelling

  # well sometimes there are complex data types such as double2 (cuDoubleComplex) .. there the pointer is smaller then the datatype.
  # all sizeof() will be determined at compile time, hence no performance loss ...
  O_PARMDEF['T2D_STRUCT_ARGS'] = [ Template("""union {
                                                 struct { 
                                                   char ___dummy0[sizeof(${PTYPE}) < ${PARM_VAL_SIZE} ? ${PARM_VAL_SIZE}-sizeof(${PTYPE}) : 0];
                                                   ${PTYPE} ptr;
                                                 };
                                                 struct {
                                                   char ___dummy1[sizeof(${PTYPE}) > ${PARM_VAL_SIZE} ? sizeof(${PTYPE})-${PARM_VAL_SIZE} : 0];
                                                   ${TYPE} ${PARM_VAL};
                                                 };
                                               }""").substitute( { "PTYPE" : p_parmtype, "TYPE" : parm_type, "PARM_VAL" : parm_val, "PARM_VAL_SIZE" : parm_val_size } ),
                                   parm.header.spelling ]


#############################################
################ T2D TRAPPER ASSIGNMENT

def t2d_struct_var__direct_assign( O_PARMDEF, parm ):
  assign_tmpl = """${STRUCT}.${PARM} = ${PARM};
                   """
  fl = { "PARM" : parm.header.spelling }
  O_PARMDEF['T2D_STRUCT_ASSIGN'] = Template(assign_tmpl).safe_substitute( fl )


def t2d_struct_assign_scalarhost_ptr_in( GLPARMS, O_PARMDEF, parm, pidx ):

  default_assign_tmpl = """${STRUCT}.${PARM_NAME}.val = *${PARM_NAME};"""
  if parm.header.type.get_pointee().kind == clang.cindex.TypeKind.VOID:
    if "cudaDataType" in parm.manual.typedep.header.type.spelling:
      val_assign_tmpl = cudaDataType_assign( parm.manual.typedep.header.spelling, "&${STRUCT}.${PARM_NAME}.val[0] /* is char! */", "${PARM_NAME}" )
    elif "cudnnTensorDescriptor" in parm.manual.typedep.header.type.spelling:
      val_assign_tmpl = cudnnDataType_assign( GLPARMS, parm.manual.typedep.header.spelling, "&${STRUCT}.${PARM_NAME}.val", "${PARM_NAME}" ) # ToDo: need the correct type!
    else:
      print("ERR: shouldn't have happened (t2d_struct_assign_scalarhost_ptr_in)! case: %s" % parm.manual.typedep.header.type.spelling);
      sys.exit(-1)
  else:
    val_assign_tmpl = default_assign_tmpl

  # in this case the bit indicates just if the value is set or not;
  tmpl = """if( ${PARM_NAME} ) {
              ${STRUCT}.${BITMAP} |= (0x1${BITMAP_TYPE_EXT} << ${BITMAP_SHIFT});
              ${VAL_ASSIGN}
            }
            else {
              ${STRUCT}.${PARM_NAME}.ptr = NULL;
            }
            """
  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx) }

  val_assign = Template(val_assign_tmpl).safe_substitute( fl )
  fl[ "VAL_ASSIGN" ] = val_assign

  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['T2D_STRUCT_ASSIGN'] = Template(tmpl).safe_substitute( fl )


def t2d_struct_assign_scalarhostordev_ptr_in( O_PARMDEF, parm, pidx, GLPARMS ):

  if parm.header.type.get_pointee().kind == clang.cindex.TypeKind.VOID:
    if "cudaDataType" in parm.manual.typedep.header.type.spelling:
      val_assign_tmpl = cudaDataType_assign( parm.manual.typedep.header.spelling, "&${STRUCT}.${PARM_NAME}.val[0]", "${PARM_NAME}" )
    else:
      print("ERR: shouldn't have happened!");
      sys.exit(-1)
  else:
    val_assign_tmpl = """${STRUCT}.${PARM_NAME}.val = *${PARM_NAME};"""

  # in this case the bit indicates just if the value is set or not
  tmpl = """if( ${PARM_NAME} ) {
              hfcuda_am_node_t* _____${PARM_NAME}_MEMCHECK = hfcuda_am_mem_check( (${PARM_TYPE_WOC}) ${PARM_NAME}, devId );
              bool _____${PARM_NAME}_PASSONHOST = ! (_____${PARM_NAME}_MEMCHECK && _____${PARM_NAME}_MEMCHECK->isdevice );
              if( _____${PARM_NAME}_PASSONHOST ) {
                ${VAL_ASSIGN}
                ${STRUCT}.${BITMAP} |= (0x1${BITMAP_TYPE_EXT} << ${BITMAP_SHIFT});
              }
              else {
                ${STRUCT}.${PARM_NAME}.ptr = ${PARM_NAME};
              }
            }
            else {
              ${STRUCT}.${PARM_NAME}.ptr = NULL;
            }
            """

  if parm.manual.memory & doc.MEMORY_HoD_CUBLASPOINTERMODE:
    None
  elif parm.manual.memory & doc.MEMORY_HoD_CUSPARSEPOINTERMODE:
    None
  else:
    None

# ToDo! above .val assignment assumes it is a pointer! -> could be pass by value as well!
# for this routine, we can assume it is a pointer, as pass by value was handled somewhere else!
  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx),
         "PARM_TYPE_WOC" : parm.header.type.spelling.replace("const","").strip() }

  val_assign = Template(val_assign_tmpl).safe_substitute( fl )
  fl[ "VAL_ASSIGN" ] = val_assign

  GLPARMS['REQ_DEVID'] = True
  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['T2D_STRUCT_ASSIGN'] = Template(tmpl).safe_substitute( fl )


def t2d_struct_assign_scalarhostordev_out( O_PARMDEF, parm, pidx, GLPARMS ):

  # in this case the bit indicates just if the value is set or not
  tmpl = """${STRUCT}.${PARM_NAME} = ${PARM_NAME};
            if( ${PARM_NAME} ) {
              hfcuda_am_node_t* _____${PARM_NAME}_MEMCHECK = hfcuda_am_mem_check( (${PARM_TYPE_WOC}) ${PARM_NAME}, devId );
              ${BITMAP_TYPE} _____${PARM_NAME}_PASSONHOST = ! (_____${PARM_NAME}_MEMCHECK && _____${PARM_NAME}_MEMCHECK->isdevice );
              ${STRUCT}.${BITMAP} |= ((_____${PARM_NAME}_PASSONHOST & 0x1${BITMAP_TYPE_EXT}) << ${BITMAP_SHIFT});
            }
            """

  # ToDo
  if parm.manual.memory & doc.MEMORY_HoD_CUBLASPOINTERMODE:
    None
  elif parm.manual.memory & doc.MEMORY_HoD_CUSPARSEPOINTERMODE:
    None
  else:
    None

  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx),
         "PARM_TYPE_WOC" : parm.header.type.spelling.replace("const","").strip() }
  if not isPointerOrArray( parm.header.type.kind ):
    fl["PARM_NAME"] = "&%s" % trap_cat2_filler["PARM_NAME"]
    fl["PARM_TYPE_WOC"] += "*"

  GLPARMS['REQ_DEVID'] = True
  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['T2D_STRUCT_ASSIGN'] = Template(tmpl).safe_substitute( fl )

  
def t2d_struct_assign_vectorhostordev_in( O_PARMDEF, parm, pidx, GLPARMS ):

  tmpl = """${STRUCT}.${PARM_NAME} = ${PARM_NAME};
            if( ${PARM_NAME} ) {
              hfcuda_am_node_t* _____${PARM_NAME}_MEMCHECK = hfcuda_am_mem_check( (${PARM_TYPE_WOC}) ${PARM_NAME}, devId );
              ${BITMAP_TYPE} _____${PARM_NAME}_PASSONHOST = ! (_____${PARM_NAME}_MEMCHECK && _____${PARM_NAME}_MEMCHECK->isdevice );
              ${STRUCT}.${BITMAP} |= ((_____${PARM_NAME}_PASSONHOST & 0x1${BITMAP_TYPE_EXT}) << ${BITMAP_SHIFT});
              if(  _____${PARM_NAME}_PASSONHOST ) {
                memcpy( &${STRUCT}.${BUF_NAME}[ ${BUF_CUROFFSET} ], ${PARM_NAME}, ${LENGTH} );
                ${BUF_CUROFFSET} += ${LENGTH};
              }
            }
            """

  if parm.manual.memory & doc.MEMORY_HoD_CUBLASPOINTERMODE:
    None
  elif parm.manual.memory & doc.MEMORY_HoD_CUSPARSEPOINTERMODE:
    None
  else:
    None

  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx), 
         "PARM_TYPE_WOC" : parm.header.type.spelling.replace("[]", "*").replace("const","").strip() }
  
  ptype = get_pointee_ptype( parm )

  if parm.manual.type & doc.VECTOR: # need a dynamic allocated buffer!
    fl["LENGTH"] = "%s * sizeof(%s)" % ( parm.manual.length, ptype )
  else: # static buffer is fine!
    fl["LENGTH"] = "sizeof(%s)" % ptype

  GLPARMS['REQ_DEVID'] = True
  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['T2D_STRUCT_ASSIGN'] = Template(tmpl).safe_substitute( fl )



#############################################
################ cleanup
  

def cat2_vectors( O_PARMDEF, parm, pidx, GLPARMS ):

  # the idea is: we always send the pointer within the trapper.
  # if it is a pointer in the device, we are totally fine.
  # if it is a pointer on the host:
  #         we create a buffer on the daemon
  #         send the data from trapper to daemon
  #         patch the address within the struct to the daemon buffer

  daemon_tmpl = """if( (${STRUCT}.${BITMAP} >> ${BITMAP_SHIFT}) & 0x1 ) {
                     ${STRUCT}.${PARM_NAME} = (${PARM_TYPE}) &${BUF_NAME}[ ${BUF_POS} ];
                     hfcheck( hfcuda_comm_recv( (${PARM_TYPE_WOC}) ${STRUCT}.${PARM_NAME}, ${LENGTH} ));
                   }
                   """
  fl = { "BITMAP_SHIFT" : str(pidx),
         "PARM_TYPE" : parm.header.type.spelling.replace("[]", "*"),
         "PARM_TYPE_WOC" : parm.header.type.spelling.replace("[]", "*").replace("const", "").strip(),
         "PARM_NAME" : parm.header.spelling }
  out = {}
  
  ptype = get_pointee_ptype( parm )
 
  if parm.manual.type & doc.VECTOR: # need a dynamic allocated buffer!
    out['BUF_LEN'] = "%s * sizeof(%s)" % ( parm.manual.length, ptype )
    out['D_BUF_LEN'] = "${STRUCT}.%s * sizeof(%s)" % ( parm.manual.length, ptype )
    fl["LENGTH"] = out['D_BUF_LEN']
    out['BUF_STATIC'] = False
  else: # static buffer is fine!
    out['BUF_LEN'] = out['D_BUF_LEN'] = fl["LENGTH"] = "sizeof(%s)" % ptype
    out['BUF_STATIC'] = True

  out['DAEMON'] = Template(daemon_tmpl).safe_substitute( fl )

  O_PARMDEF['REQ_BITMAP'] = True
  return out










#############################################
################ D2T VARIABLE

def d2t_struct_var( O_PARMDEF, parm ):
  if parm.header.type.get_pointee().kind == clang.cindex.TypeKind.VOID:
    if "cudaDataType" in parm.manual.typedep.header.type.spelling:
      ptype, pspell, DISCARD = cudaDataType_parm_val_size( parm.header.spelling )
    else:
      print("ERR: shouldn't have happened!");
      sys.exit(-1)

    print("ToDo")
    exit(-1)
  else:
    ptype = get_pointee_ptype( parm )
    pspell = parm.header.spelling

  if parm.manual.type & doc.CONST_VECTOR:
    pspell += "[%d]" % parm.manual.length

  O_PARMDEF["D2T_STRUCT_ARGS"] = [ ptype, pspell ]



#############################################
################ D2T WRITEBACK

def d2t_struct_writeback__scalarhost( O_PARMDEF, parm ):
  to_user = """if( ${PARM_NAME} ) *${PARM_NAME} = ${D2T_STRUCT}.${PARM_NAME};
               """

  fl = { "PARM_NAME" : parm.header.spelling }
  O_PARMDEF['D2T_STRUCT_TO_USER'] = Template(Template(to_user).safe_substitute( fl ))

def d2t_struct_writeback__scalarhostordev( O_PARMDEF, parm, pidx ):
  if parm.manual.type & doc.CONST_VECTOR:
    wr = """memcpy(${PARM_NAME}, ${D2T_STRUCT}.${PARM_NAME}, sizeof(${D2T_STRUCT}.${PARM_NAME}));""" 
  elif parm.manual.type & doc.SCALAR:
    wr = """*${PARM_NAME} = ${D2T_STRUCT}.${PARM_NAME};"""
  else:
    print("not supported right now!")
    exit(-1)

  to_user = """if( ${PARM_NAME} && ((${T2D_STRUCT}.${BITMAP} >> ${BITMAP_SHIFT}) & 0x1) ) {
                 %s
               }
               """ % wr # to avoid 2x safe_substitute as of PARM_NAME .. just use regular Python string...

  fl = { "PARM_NAME" : parm.header.spelling, "BITMAP_SHIFT" : str(pidx),
         "WRITEBACK" : wr }
  O_PARMDEF['REQ_BITMAP'] = True
  O_PARMDEF['D2T_STRUCT_TO_USER'] = Template(Template(to_user).safe_substitute( fl ))








# ToDo: build a chart that depicts all configurations!


def handle_parm( parm, GLPARMS ):

  o_parmdef = { 'REQ_BITMAP' : False }
  cur_pidx = GLPARMS['BITMAP_CTR'] # in case we update it, keep here current

  # 1) find all parameters that are ...
  #    a) have memory = MEMORY_DEVICE (scalar parameter)
  #    b) or          & doc.MEMORY_DEVICE (address just valid in device)
  #    c) or are pointer but are passed by value (such as const void* func, where just the function address will be passed on)
  if ( not isPointerOrArray( parm.header.type.kind )    # p.manual.memory & doc.MEMORY_UNDEF
       or parm.manual.memory & doc.MEMORY_DEVICE
       or ( isPointerOrArray( parm.header.type.kind )
           and parm.manual.memory & doc.PASSBYVALUE) ):
    t2d_struct_var( o_parmdef, parm )
    t2d_struct_var__direct_assign( o_parmdef, parm )
    t2d_struct_fncparm( o_parmdef, parm )

  # 2) find INPUT that is host or device
  #    -> in this case we query on the trapper side if memory is host or device
  #    -> in case of device : send pointer and bit indicating that on decvice
  #    -> in case of host   : send pointer (although not required) and bit indicating that subsequent send will occure
  #          --> if host is scalar, just send the data on the stack and indicate with bit!
  elif ( parm.manual.inout == doc.INOUT_IN
         and ( parm.manual.memory & doc.MEMORY_HOSTORDEV
               or parm.manual.memory & doc.MEMORY_HOST ) ):

    # this is an optimization. In this case we can just pass the value on the struct!
    # if it is not given (as of NULL ptr, don't mind -> there is a bitmap indicating it for the daemon)
    if parm.manual.type & doc.SCALAR:
      t2d_struct_var__scalarhostordev_ptr( o_parmdef, parm )
      if parm.manual.memory & doc.MEMORY_HOST:
        # we still use the struct here -> if nullpointer supplied, we also provide null pointer on the other side!
        t2d_struct_assign_scalarhost_ptr_in( GLPARMS, o_parmdef, parm, cur_pidx )
      else: # doc.MEMORY_HOSTORDEV
        t2d_struct_assign_scalarhostordev_ptr_in( o_parmdef, parm, cur_pidx, GLPARMS )
      t2d_struct_fncparm__scalarhostordev_in( o_parmdef, parm, cur_pidx )

      # ToDo: in this case we need to patch the parameter!
    else:
      t2d_struct_var( o_parmdef, parm )
      t2d_struct_assign_vectorhostordev_in( o_parmdef, parm, cur_pidx, GLPARMS )
      o_parmdef['T2D_VECTOR_PARM'] = cat2_vectors( o_parmdef, parm, cur_pidx, GLPARMS )
      t2d_struct_fncparm( o_parmdef, parm )

  # 3) find parameters that are being written back to host memory (pure output)
  #    can partially handle vectors with const size.
  elif ( parm.manual.inout == doc.INOUT_OUT
         and (parm.manual.memory & doc.MEMORY_HOST
              or parm.manual.memory & doc.MEMORY_HOSTORDEV)
         and (parm.manual.type & doc.SCALAR
              or parm.manual.type & doc.CONST_VECTOR) ): # ToDo: vector case!

    d2t_struct_var( o_parmdef, parm )

    if parm.manual.memory & doc.MEMORY_HOSTORDEV:
      t2d_struct_var( o_parmdef, parm )
      t2d_struct_assign_scalarhostordev_out( o_parmdef, parm, cur_pidx, GLPARMS )
      d2t_struct_fncparm__scalarhostordev_out( o_parmdef, parm, cur_pidx )
      d2t_struct_writeback__scalarhostordev( o_parmdef, parm, cur_pidx )
    else:
      if parm.manual.type & doc.CONST_VECTOR:
        print("ERROR: parameter type can not be handled with current logic! (1)")
        exit(-1)
      d2t_struct_writeback__scalarhost( o_parmdef, parm )
      d2t_struct_fncparm_scalarhost( o_parmdef, parm )
      # this is the case whenever something is just retrieved from the daemon
      # -> just write somewhere into host! (could introduce this to make a clean 'Create' function)
  
  # 4) case host/dev, scalar and in/out
  elif ( parm.manual.inout == doc.INOUT_INOUT
         and parm.manual.type & doc.SCALAR
         and parm.manual.memory & doc.MEMORY_HOSTORDEV ):

    d2t_struct_var( o_parmdef, parm )

    t2d_struct_var__scalarhostordev_ptr( o_parmdef, parm )
    t2d_struct_assign_scalarhostordev_ptr_in( o_parmdef, parm, cur_pidx, GLPARMS )
    d2t_struct_fncparm__scalarhostordev_inout( o_parmdef, parm, cur_pidx )
    d2t_struct_writeback__scalarhostordev( o_parmdef, parm, cur_pidx )

  
  # ... well ...
  else:
    print("ERROR: parameter type can not be handled with current logic!")
    exit(-1)

  if o_parmdef['REQ_BITMAP']:
    GLPARMS['BITMAP_CTR'] += 1

  # in case of cuDNN -> we need some "prolog"
  try:
    if parm.manual.set_cudnnDataType:
      GLPARMS['REQ_DEVID'] = True
      o_parmdef[ "set_cudnnDataType" ] = [ parm.manual.set_cudnnDataType, parm.header.spelling ]
  except:
    None
  try:
    if parm.manual.del_cudnnDataType:
      GLPARMS['REQ_DEVID'] = True
      o_parmdef[ "del_cudnnDataType" ] = parm.header.spelling
  except:
    None

  return o_parmdef





def assemble_parms( GLPARMS, PARMS, RET_PARM, func_name, func_enum_id, fnc_pack_manual ):

  d2t_struct_name = "d2t_msg"
  t2d_struct_name = "t2d_msg"
  t2d_struct_header_name = "header"
  t2d_struct_data_name = "data"

  d_t2d_data_struct_name = t2d_struct_name + "_" + t2d_struct_data_name # struct name t2d_msg_data
  t_t2d_curbufoffset_name = "%s_msgcuroffset" % t2d_struct_name
  
  cat2_bitmap_name = "____CAT2_BITMAP"
  cat2_daemon_bufname = "____buf"
  uint_type, val_ext = get_min_uint( GLPARMS["BITMAP_CTR"] )

  trapper_out = ""
  daemon_out = ""
  ret_val = ""

  ####################################

  # if require device id ... 
  if GLPARMS['REQ_DEVID']:
    trapper_out += "int devId;\n"
    trapper_out += "hfcheck(hfcuda_vdm_get_device(&devId));\n\n"

  ####################################

  # let's see if T2D_STRUCT required, and if so build it
  # obtain T2D_STRUCT assignment as well
  
  # the trapper and daemon T2D_STRUCT look a bit different
  #
  # trapper will send:
  #   struct __attribute__((packed)) {
  #     hf_msgdescr_t header;
  #     struct __attribute__((packed)) {
  #       [... args ...]
  #     } data;
  #   } t2d_msg;
  # hint: need to setup the header part!
  #
  # daemon will recv:
  #   struct __attribute__((packed)) {
  #     [... args ...]
  #   } data;         // let's call this t2d_msg_data!
  # reason: header part is already handled within daemon loop
  
  t2d_vars = []
  t2d_assign = []

  # the bitmap needs to be the first that gets assigned of the data struct
  # reason: any other assignment could make modifications to it!
  if GLPARMS['BITMAP_CTR'] > 0:
    t2d_vars.append( [ uint_type, cat2_bitmap_name ] )
    t2d_assign.append( "${STRUCT}.%s = 0%s;\n" % (cat2_bitmap_name, val_ext) )

  buf_sum_len = []
  d_buf_sum_len = []
  for parm in PARMS:
    if 'T2D_STRUCT_ARGS' in parm:
      t2d_vars.append(parm['T2D_STRUCT_ARGS'])
    if 'T2D_STRUCT_ASSIGN' in parm:
      dpatch = { "BITMAP_TYPE_EXT" : val_ext,
                 "BITMAP_TYPE" : uint_type,
                 "BITMAP" : cat2_bitmap_name,
                 "BUF_POS" : '0' if not len(buf_sum_len) else " + ".join(buf_sum_len),
                 "BUF_NAME" : cat2_daemon_bufname,
                 "BUF_CUROFFSET" : t_t2d_curbufoffset_name }
      asgn = Template(parm['T2D_STRUCT_ASSIGN']).safe_substitute( dpatch )
      t2d_assign.append(asgn)
      
      if "T2D_VECTOR_PARM" in parm:
        buf_sum_len.append( parm['T2D_VECTOR_PARM']['BUF_LEN'] )
        d_buf_sum_len.append( Template(parm['T2D_VECTOR_PARM']['D_BUF_LEN']).safe_substitute( { "STRUCT" : d_t2d_data_struct_name } ) )


  # after all of the parms are in the struct, let's check if we require a dynamic length!
  buf_static = True
  for parm in PARMS:
    if 'T2D_VECTOR_PARM' in parm:
      if buf_static:
        buf_static = parm['T2D_VECTOR_PARM']['BUF_STATIC']
  if not buf_static:
    t2d_vars.append( [ "char", "%s[]" % cat2_daemon_bufname ] )

  # before setting anything else into the struct, let's set the function id!
  t_t2d_header_assign_str = Template("""HF_MSGDESCR_SET( ${PSTRUCT_HEADER}, ${FNC_ENUM_ID} );""").substitute( { "FNC_ENUM_ID" : func_enum_id,
                                                           "PSTRUCT_HEADER" : "&%s->%s" % (t2d_struct_name, t2d_struct_header_name) } )

  t_t2d_msg_struct_vars = [ [ "hf_msgdescr_t", t2d_struct_header_name ] ]
  if len(t2d_vars):
    t2d_data_struct_str = gen_struct( t2d_vars, True )
    t_t2d_msg_struct_vars.append( [ t2d_data_struct_str, t2d_struct_data_name ] )

    d_t2d_msg_data_struct_str = t2d_data_struct_str + " " + d_t2d_data_struct_name + ";\n"
    daemon_out += gen_recv_struct( d_t2d_msg_data_struct_str, "&" + d_t2d_data_struct_name, "sizeof(%s)" % d_t2d_data_struct_name )

  t_t2d_msg_struct_str = gen_struct( t_t2d_msg_struct_vars, True ) + " * " + t2d_struct_name + ";\n"
  # ToDo: if const / dynamic


  ####################################

  # ok, there might be some buffers that need to transfered
  # 1) what's the sum length and do we need dynamic or is static fine?
  d_buf_sum_len = []
  for parm in PARMS:
    if 'T2D_VECTOR_PARM' in parm:
      # before we add, patch the BUF_POS!
      dpatch = { 'BUF_POS' : '0' if not len(d_buf_sum_len) else " + ".join(d_buf_sum_len),
                 'BUF_NAME' : cat2_daemon_bufname,
                 'STRUCT' : d_t2d_data_struct_name,
                 'BITMAP' : cat2_bitmap_name }

      parm['T2D_VECTOR_PARM']['DAEMON'] = Template( parm['T2D_VECTOR_PARM']['DAEMON'] ).substitute( dpatch )
      d_buf_sum_len.append( Template(parm['T2D_VECTOR_PARM']['D_BUF_LEN']).safe_substitute( { "STRUCT" : d_t2d_data_struct_name } ) )




  # send function!
  t_t2d_msg_minlen = "sizeof(*%s)" % t2d_struct_name
  if buf_static:
    t_t2d_msg_struct_str += Template("""typeof(*${NAME}) ____constSize_${NAME};\n ${NAME} = &____constSize_${NAME}; /* constant buffer size */\n""").substitute( { "NAME" : t2d_struct_name } ) 
    t_t2d_msg_len = t_t2d_msg_minlen
  else:
    t_t2d_msg_maxlen = "%s + %s" % (t_t2d_msg_minlen, " + ".join(buf_sum_len))
    t_t2d_msg_len = "%s + %s" % (t_t2d_msg_minlen, t_t2d_curbufoffset_name)
    t_t2d_msg_struct_str += Template("""unsigned int ${NAME}_maxlen = ${STRUCT_MAXLEN};
                                        unsigned int ${BUF_CUROFFSET} = 0;
                                        ${NAME} = ( typeof(${NAME}) ) malloc ( ${NAME}_maxlen );""" ).substitute(
                                        { "NAME" : t2d_struct_name,
                                          "STRUCT_MAXLEN" : t_t2d_msg_maxlen,
                                          "BUF_CUROFFSET" : t_t2d_curbufoffset_name } ) 
    
  trapper_out += t_t2d_msg_struct_str + "\n"
  
  
  t_t2d_data_assign = gen_assign( t2d_struct_name + "->" + t2d_struct_data_name, t2d_assign )
  t_t2d_data_assign_str = "".join( t_t2d_data_assign )
  trapper_out += t_t2d_header_assign_str + "\n"
  trapper_out += t_t2d_data_assign_str + "\n"
  trapper_out += gen_send_func( t2d_struct_name, t_t2d_msg_len )
        
  # 2) before we do the trapper send -> recv daemon, we need to make a buffer on the daemon side!
  daemon_epilog = "" # ToDo at end! free the allocation
  if len(buf_sum_len):
    if buf_static:
      daemon_out += "char %s[%s];\n" % (cat2_daemon_bufname, " + ".join(buf_sum_len))
    else:
      tout = """char *${BUF_NAME} = (char*) malloc ( ${BUF_SIZE} );
                """
      epout = """free( ${BUF_NAME} );
                 """
      tfill = { "BUF_NAME" : cat2_daemon_bufname,
                "BUF_SIZE" : " + ".join(d_buf_sum_len) }
      daemon_out += Template(tout).substitute(tfill)
      daemon_epilog = "\n" + Template(epout).substitute(tfill)

  # 3) put trapper and daemon part into out strings
  #    in this case 
  for parm in PARMS:
    if 'T2D_VECTOR_PARM' in parm:
      daemon_out += parm['T2D_VECTOR_PARM']['DAEMON']

  # 4) don't forget epilog part!

  ####################################

  d2t_vars = []
  d2t_return = ""

  # Now, let's handle the function call itself.
  # it is clear that we need to create another struct
  # to send data to the other side. But first handle the function so that it
  # can be just inserted at the right place!
  # Reason: function returns a value that needs to be put into the struct as well
  #         hence it is like an assignment.
  
  fnc_parms = []
  for parm in PARMS:
    fl = { "T2D_STRUCT" : d_t2d_data_struct_name,
           "D2T_STRUCT" : d2t_struct_name,
           "BITMAP"     : cat2_bitmap_name }
    fnc_parms.append(parm["D_FUNC_PARM"].substitute(fl))
  function = "%s( %s )" % (func_name, ", ".join(fnc_parms))

  # if function returns scalar -> put it into the d2t_vars and function into d2t_return
  if ( not isPointerOrArray( RET_PARM.kind )
       and RET_PARM.kind != clang.cindex.TypeKind.VOID ):
    try:
      pspell = fnc_pack_manual.____RETVAL.typepatch # patched
    except:
      pspell = RET_PARM.spelling # default return whatever from header
    d2t_vars.append( [ pspell, "____RETVAL" ] )
    d2t_return = [ "____RETVAL", function ]
  else:
    print("Not yet supported!\n")
    exit(-1)

  ####################################

  d2t_userspace_assign = []

  # Start adding the other parts
  for parm in PARMS:
    if 'D2T_STRUCT_ARGS' in parm:
      d2t_vars.append(parm['D2T_STRUCT_ARGS'])
    if 'D2T_STRUCT_TO_USER' in parm:
      d2t_userspace_assign.append(parm['D2T_STRUCT_TO_USER'])

  if len(d2t_vars):
    # ToDo: make an option available to put values into d2t before or after the function!
    d2t_msg_struct_str = gen_struct( d2t_vars ) + " " + d2t_struct_name + ";"
    daemon_out += d2t_msg_struct_str + "\n"
    # check if pre-func templates are given, then it needs to be set before d2t_return assignment!
    prefunc_assign = []
    for parm in PARMS:
      fl = { "T2D_STRUCT" : d_t2d_data_struct_name,
             "D2T_STRUCT" : d2t_struct_name }
      if 'D2T_STRUCT_PREFUNC_ASSIGN' in parm:
        prefunc_assign.append(Template(parm['D2T_STRUCT_PREFUNC_ASSIGN']).substitute(fl))
    if len(prefunc_assign):
      daemon_out += "\n".join(prefunc_assign) + "\n"

    daemon_out += gen_assign( d2t_struct_name, [ "${STRUCT}.%s = %s;\n" % (d2t_return[0], d2t_return[1]) ] )[0] + "\n"
    daemon_out += gen_send_func( "&" + d2t_struct_name, "sizeof(%s)" % d2t_struct_name )

    trapper_out += gen_recv_struct( d2t_msg_struct_str, "&" + d2t_struct_name, "sizeof(%s)" % d2t_struct_name, )


    # we need to write the obtaines values back. Hence in case of scalar:
    for a in d2t_userspace_assign:
      trapper_out += a.substitute( { "D2T_STRUCT" :  d2t_struct_name, "T2D_STRUCT" : t2d_struct_name + "->" + t2d_struct_data_name, "BITMAP" : cat2_bitmap_name } )


  # ToDo: case when vectors are being returned!
  # ToDo: double check what happens if structs that are being returned!

  ####################################

  # struct is set up already, if the function has no return type, we need to call it now!
  # otherwise it is already within the assignment
  if RET_PARM.kind == clang.cindex.TypeKind.VOID:
    daemon_out += function + ";\n"
  else:
    ret_val = "%s.%s" % (d2t_struct_name, "____RETVAL")

  if ( RET_PARM.spelling == "cudaError_t"
       or RET_PARM.spelling == "cusparseStatus_t"
       or RET_PARM.spelling == "cublasStatus_t"
       or RET_PARM.spelling == "cudnnStatus_t" ):
    trapper_out += """hfinf( "[trapper] %s() [DONE] status=%%d\\n", %s.%s );""" % (func_name, d2t_struct_name, "____RETVAL" )
    daemon_out += """hfinf( "[daemon] %s() [DONE] status=%%d\\n", %s.%s );""" % (func_name, d2t_struct_name, "____RETVAL" )

    if RET_PARM.spelling == "cudnnStatus_t":
      # in case of cuDNN, we need to sometimes store the datatype.
      # as of this we are looking into parms and check if "set_cudnnDataType" is set!
      asgn = {}
      for parm in PARMS:
        if "set_cudnnDataType" in parm:
          asgn[ parm[ "set_cudnnDataType" ][0] ] = parm[ "set_cudnnDataType" ][1]

      if asgn != {}:
        tmpl = """if( ${D2T_STRUCT}.____RETVAL == CUDNN_STATUS_SUCCESS ) {
                    hfcheck(hfcuda_set_cudnnDataType( devId, ${DESCR}, ${DATATYPE} ));
                  }
                  """
        asgn[ "D2T_STRUCT" ] = d2t_struct_name
        trapper_out += "\n" + Template(tmpl).substitute(asgn)

      for parm in PARMS:
        if "del_cudnnDataType" in parm:
          tmpl = """if( ${D2T_STRUCT}.____RETVAL == CUDNN_STATUS_SUCCESS ) {
                      hfcheck(hfcuda_del_cudnnDataType( devId, ${DESCR} ));
                    }
                    """
          asgn[ "DESCR" ] = parm[ "del_cudnnDataType" ]
          asgn[ "D2T_STRUCT" ] = d2t_struct_name
          trapper_out += "\n" + Template(tmpl).substitute(asgn)
	
  else:
    trapper_out += """hfinf( "[trapper] %s() [DONE]\\n" );""" % func_name
    daemon_out += """hfinf( "[daemon] %s() [DONE]\\n" );""" % func_name

  ####################################
  
  # and let's don't forget the epilog
  daemon_out += daemon_epilog

  return [ trapper_out, daemon_out, ret_val ]



def gen_trapper_and_daemon(fnc_pack):

  GLPARMS = { 'REQ_DEVID' : False,
              'BITMAP_CTR' : 0 }
  PARMS = []
  fnc_args = []
  for p in fnc_pack.merged_parm_def:
    PARMS.append( handle_parm( p, GLPARMS ) )


    fnc_args.append( "%s %s" % get_ptype_pname(p) )

  fnc = fnc_pack.header
  func_enum_id = "HFCUDA_%s" % fnc.spelling
  out_trap, out_daemon, ret_val = assemble_parms( GLPARMS, PARMS, fnc.type.get_result(), fnc.spelling, func_enum_id, fnc_pack.manual )

#######################################################################

  trapper_tmpl = """/*************************************************
                    * DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
                    *************************************************/
                    ${FNC_RESULT_TYPE}
                    ${FNC_DECL} ( ${FNC_ARGS} )
                    {
                      hfinf( "[trapper] ${FNC_DECL}() [CALL]\\n" );

                      ${D2T_HANDLING}
                      return ${T2D_STATUS};
                    }"""

  trap_cnt = {}
  trap_cnt["FNC_DECL"] = fnc.spelling
  trap_cnt["FNC_ARGS"] = ", ".join(fnc_args) if len(fnc_args) else "void"
  try:
    ret_spell = fnc_pack.manual.____RETVAL.typepatch
  except:
    ret_spell = fnc.type.get_result().spelling
  trap_cnt["FNC_RESULT_TYPE"] = ret_spell
  trap_cnt["D2T_HANDLING"] = out_trap
  trap_cnt["T2D_STATUS"] = ret_val
  
  trapper_impl = Template(trapper_tmpl).substitute(trap_cnt)


  daemon_tmpl = """/*************************************************
                   * DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
                   *************************************************/
                   hferr_t
                   handle_HFCUDA_${FNC_DECL} ( void )
                   {
                     hfinf( "[daemon] ${FNC_DECL}() [CALL]\\n" );

                     ${T2D_HANDLING}
                     ${EPILOG}
                     return HFOK;
                   }"""

  tmp_args = {}
  tmp_args["FNC_DECL"] = fnc.spelling
  tmp_args["T2D_HANDLING"] = out_daemon
  tmp_args["EPILOG"] = "" # daemon_epilog
  daemon_impl = Template(daemon_tmpl).substitute(tmp_args)

  return (fix_indent(trapper_impl), fix_indent(daemon_impl), func_enum_id)





#// cudaThreadSetCacheConfig, cudaMemcpyToSymbolAsync, cudaFuncGetAttributes



fnc_show_debug = [ "cudnnSetTensorNdDescriptor" ]
debug = False

hfcuda_dir = "../hfcuda"
cuda_dir = "/shared/opt/cuda/cuda-9.1/"




fh_trapper_out = ""
fh_daemon_out = ""
hfcuda_func_enums = []
i = 0
for fnc, fnc_def in iter(sorted(spec.get_defs( cuda_dir ).iteritems())):
  if ( not debug
       or fnc in fnc_show_debug ):
    print("[%3d] BACKING: %s" % (i, fnc) )
    trapper, daemon, func_enum_id = gen_trapper_and_daemon(fnc_def)
    fh_trapper_out += trapper + "\n\n\n"
    fh_daemon_out += daemon + "\n\n\n"
    hfcuda_func_enums.append( func_enum_id )
    if fnc in fnc_show_debug:
      print(trapper)
      print(daemon)
  i += 1

def file_add_auto( fname, autolines ):
  fh = io.open( fname, 'r+')

  fh_func_lines_new = []
  lines = iter(fh)
  for line in lines:
    fh_func_lines_new.append(line)
    if "AUTO GENERATED" in line:
      fh_func_lines_new += autolines
      line = lines.next()
      while "AUTO GENERATED" not in line:
        line = lines.next()
      fh_func_lines_new.append(line)

  fh.seek(0)
  fh.writelines( [unicode(l) for l in fh_func_lines_new] )
  fh.close()

if not debug:
  fh_trapper = io.open(os.path.join(hfcuda_dir, "wrappers/trapper_fnc_auto.c"), 'w')
  fh_trapper.write(unicode(fh_trapper_out))
  fh_trapper.close()

  fh_daemon = io.open(os.path.join(hfcuda_dir, "wrappers/daemon_fnc_auto.c"), 'w')
  fh_daemon.write(unicode(fh_daemon_out))
  fh_daemon.close()


  hfcuda_func_add = [ "    %s,\n" % e for e in hfcuda_func_enums ]
  file_add_auto( os.path.join(hfcuda_dir, "modules/hfcuda_functions.h" ), hfcuda_func_add )

  hfcuda_daemon_add = [ "        case %s:\n            return handle_%s();\n" % (e, e) for e in hfcuda_func_enums ]
  file_add_auto( os.path.join(hfcuda_dir, "hfcuda_daemon.c" ), hfcuda_daemon_add )


