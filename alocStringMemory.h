#ifndef STRINGFUNCTIONS_allocStringMemory
#define TRINGFUNCTIONS_allocStringMemory
#include "classbase.h"
#include <stdlib.h>

mystr c_StringFunctions::allocStringMemory(int size){
  mystr returnValue=(mystr)malloc(size*sizeof(char));
  if(returnValue==NULL)setLastErro(STRINGFUNCTION_LASTERRO_MALLOCERROR);
  return returnValue;
}

#endif // STRINGFUNCTIONS_geString
