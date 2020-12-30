#ifndef STRINGFUNCTIONS_reallocStringMemory
#define TRINGFUNCTIONS_reallocStringMemory
#include "classbase.h"
#include <stdlib.h>

mystr c_StringFunctions::reallocStringMemory(mystr str,int size){
  mystr returnValue;
  if(str!=NULL){
    returnValue=(mystr)realloc(str,size);
  }else{
    returnValue=(mystr)malloc(size*sizeof(char));
  }
  if(returnValue==NULL){
    setLastErro(STRINGFUNCTION_LASTERRO_MALLOCERROR);
  }
  return returnValue;
}

#endif // STRINGFUNCTIONS_geString

