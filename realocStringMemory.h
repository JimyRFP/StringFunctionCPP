#ifndef STRINGFUNCTIONS_reallocStringMemory
#define TRINGFUNCTIONS_reallocStringMemory
#include "classbase.h"
#include <stdlib.h>

mystr c_StringFunctions::reallocStringMemory(mystr str,int size){
    mystr returnValue;
    returnValue=(mystr)realloc(str,size);
    return returnValue;
}

#endif // STRINGFUNCTIONS_geString

