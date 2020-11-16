#ifndef STRINGFUNCTIONS_geString
#define STRINGFUNCTIONS_geString
#include "classbase.h"
#include<stdio.h>
mystr c_StringFunctions::getString(){
 resetLastErro();
 const size_t ind=getStringLen();
 if(ind<1)return NULL;
 mystr returnValue=allocStringMemory(ind+1);
 if(returnValue==NULL)return NULL;
 for(size_t i=0;i<=ind;i++){
  *(returnValue+i)=*(m_string+i);
 }

 return returnValue;
};

#endif
