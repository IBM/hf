import clang.cindex
import sys
import pprint

MEMORY_HOST      = (1 << 0)
MEMORY_DEVICE    = (1 << 1)
MEMORY_HOSTORDEV = (1 << 2)
PASSBYVALUE      = (1 << 3)
MEMORY_HoD_CUBLASPOINTERMODE = (1 << 4) | MEMORY_HOSTORDEV
MEMORY_HoD_CUSPARSEPOINTERMODE = (1 << 5) | MEMORY_HOSTORDEV

VECTOR           = (1 << 6)
CONST_VECTOR     = VECTOR | (1 << 7)
SCALAR           = (1 << 8)

INOUT_IN         = (1 << 9)
INOUT_OUT        = (1 << 10)
INOUT_INOUT      = (INOUT_IN | INOUT_OUT)


class parm_def:
  def __init__(self, name, memory, inout, additional={}):
    self.name = name
    
    memmask = ( MEMORY_HOST | MEMORY_DEVICE | MEMORY_HOSTORDEV | PASSBYVALUE | MEMORY_HoD_CUBLASPOINTERMODE | MEMORY_HoD_CUSPARSEPOINTERMODE )
    typemask = ( VECTOR | CONST_VECTOR | SCALAR )
    iomask = INOUT_INOUT
    if not isinstance(memory, list):
      self.memory = memory & memmask
    else:
      self.memory = memory[0] & memmask
      self.type = memory[1] & typemask
      if memory[1] & VECTOR and len(memory) > 2:
        self.length = memory[2]
        if len(memory) > 3:
          self.stride = memory[3]
        else:
          self.stride = 1
    self.inout = inout & iomask

    for k, v in additional.iteritems():
      if not ( k == "typedep"
               or k == "typepatch"
               or k == "set_cudnnDataType"
               or k == "del_cudnnDataType" ):
        print("ERR: additional parameter details not recognized: %s" % k )
        exit(-1)
      setattr( self, k, v )

class ret_def:
  def __init__(self, additional={}):
    for k, v in additional.iteritems():
      if not ( k == "typedep"
               or k == "typepatch" ):
        print("ERR: additional parameter details not recognized: %s" % k )
        exit(-1)
      setattr( self, k, v )


class func_decl:
  def __init__(self, funcs, parms = [] ):
    self.funcs = funcs
    retval_set = False
    for parm in parms:
      if isinstance(parm, parm_def):
        setattr(self, parm.name, parm)
      else:
        if retval_set:
          print("ERR: only one 'return' possible!")
          sys.exit(-1)
        retval_set = True
        setattr(self, "____RETVAL", parm)


def gen_func_decl(header_file, fnc_decls, verbose = 0):
  # https://stackoverflow.com/questions/15388961/extract-type-string-with-clang-bindings
  # https://stackoverflow.com/questions/47642009/libclang-python-how-to-get-number-of-arguments-for-function-with-default-values
  # good example: https://reviews.llvm.org/D39763
  index = clang.cindex.Index.create()
  tu = index.parse(header_file)

  print("Status: %d API defs. for %s" % (len(fnc_decls), header_file))

  fncs = {}
  for header_node in tu.cursor.walk_preorder():
    if header_node.kind == clang.cindex.CursorKind.FUNCTION_DECL:
      doc_node = None
      for f in fnc_decls:
        if header_node.spelling in f.funcs:
          doc_node = f
          break

      if doc_node != None:
        fdecl = lambda: None
        fdecl.header = header_node
        fdecl.manual = doc_node
        fdecl.merged_parm_def = [] # needs to stay in order! -> no dict() possible!
        parm_defs = {}

        for parm in header_node.get_arguments():
          parm_def = lambda: None
          parm_def.header = parm
          try:
            parm_def.manual = getattr(doc_node, parm.spelling)
          except:
            print("ERROR: couldn't find parm %s in func %s" % (parm.spelling, header_node.spelling))
            sys.exit(-1);
          
          fdecl.merged_parm_def.append( parm_def )
          parm_defs[ parm.spelling ] = parm_def
          #print("-------")
          #print(parm.type.is_const_qualified.__dict__)
          #print(parm.type.spelling)
          #print(parm.type.kind)
          #print(parm.type.kind == clang.cindex.TypeKind.POINTER)
          #if parm.type.kind == clang.cindex.TypeKind.POINTER:
          #  print("--> %s" % parm.type.get_pointee().spelling)
          #  print("--> %s" % parm.type.get_pointee().get_typedef_name())
          #print(parm.type.get_canonical().kind)
          #print(parm.type.get_canonical().kind == clang.cindex.TypeKind.POINTER)
          #print(parm.type.get_typedef_name())
          #print(parm.type.is_const_qualified()) # only sets true if const SCALAR        
        fncs[ header_node.spelling ] = fdecl

        # need to analyse the parms after all of them are 'read':
        # reason is the 'typedep':
        for parm_def in fdecl.merged_parm_def:
          typedep = "____"
          try:
            typedep = getattr( parm_def.manual, "typedep" )
          except:
            None
          if typedep != "____":
            if typedep not in parm_defs:
              print(header_node.spelling)
              print("ERR: provided typedep %s not given!" % typedep)
              pprint.pprint( parm_defs )
              exit(-1)
            else:
              parm_def.manual.typedep = parm_defs[ typedep ] # overwrite string with actual object

  return fncs

