#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "hfdemangle.h"

// this is a hack and very ugly but to quickly get things going
// reimplement an own demangle function based on AST
// ToDo: 1) create own demangling that doesn't require string creation and parsing
//       2) cache requests (potentially build all calls during LD_PRELOAD init()
//       3) support struct { ... } as parm -> GDB depicts that is passed by C++ reference, question: how to retrieve size?
//       4) modify the size -> use bit indicators for size 0x0: 1, 0x1: 2, 0x2: 4, 0x3: 8 byte

unsigned int hfdettype( const char* bgn, const char* end )
{
  const char* __bgn = bgn;
//  const char* __end = end;

  // check first if pointer!
  --end;
  while( *end == ' ' )
    --end;
  if( *end == '*' )
    return sizeof(uintptr_t);

  int run = 1;
  while( run ) {
    while( *bgn == ' ' )
      ++bgn;

    switch(bgn[0]) {
    case 'u': // unsigned
      bgn += strlen("unsigned");
      break;
    case 's':
      if( bgn[1] == 'i' ) // signed
        bgn += strlen("signed");
      else // short
        run = 0;
      break;
    case 'c':
      if( bgn[1] == 'o' ) // const
        bgn += strlen("const");
      else // char
        run = 0;
      break;
    
    default:
      run = 0;
      break;
    }
  }

  switch(bgn[0]) {
  case 'c': // char
    return sizeof(char);
  case 's': // short
    return sizeof(short);
  case 'i': // int
    return sizeof(int);
  case 'f': // float
    return sizeof(float);
  case 'd': // double
    return sizeof(double);
  case 'l': // long or long long
    bgn += strlen("long");
    while( *bgn == ' ' )
      ++bgn;
    if( *bgn == 'l' )
      return sizeof(long long);
    else
      return sizeof(long);
  default:
    fprintf(stderr, "couldn't parse value: '%s' ('%c')\n", __bgn, bgn[0]);
    exit(-1);
  }
  return 0; // shouldn't happen
}

int hfdemangle( const char* cxxname, unsigned int *parmc, unsigned int** parmtypesizes )
{
  if( ! cxxname
      || ( ! parmc && ! parmtypesizes) )
    return -1;

  int status;
  char* tmp = __cxa_demangle(cxxname, 0, 0, &status);
  if( tmp == NULL )
    return -1;

  printf("demangling: %s\n", tmp );

  unsigned int __parmc = 0;
  unsigned int *__parmtypesizes = (unsigned int *) malloc ( 0 ); // required for realloc

  char* t_tmp = tmp;
  int run = 1;
  int detparms = 0;
  char *bgn_parm = NULL;
  char *end_parm = NULL;
  while( run ) {
    switch (*t_tmp) {
    case ')':
      if(detparms) {
        ++__parmc;
        __parmtypesizes = realloc( __parmtypesizes, __parmc * sizeof(*__parmtypesizes) );
        end_parm = t_tmp;
        __parmtypesizes[ __parmc - 1 ] = hfdettype( bgn_parm, end_parm );
      }
      run = 0;
      break;
    case '\0':
      run = 0;
      break;
    case '(':
      detparms = 1;
      bgn_parm = t_tmp + 1;
      break;
    case ',':
      if(detparms) {
        ++__parmc;
        __parmtypesizes = realloc( __parmtypesizes, __parmc * sizeof(*__parmtypesizes) );
        end_parm = t_tmp;
        __parmtypesizes[ __parmc - 1 ] = hfdettype( bgn_parm, end_parm );
        bgn_parm = t_tmp + 1;
      }
    }
    ++t_tmp;
  }

  if( parmc )
    *parmc = __parmc;
  if( parmtypesizes )
    *parmtypesizes = __parmtypesizes;
  else
    free( __parmtypesizes );
  
  free(tmp);
  return 0;
}
