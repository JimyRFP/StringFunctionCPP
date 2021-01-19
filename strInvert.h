#ifndef STRINGFUNCTIONS_STRINVERT
#define STRINGFUNCTIONS_STRINVERT
bool c_StringFunctions::strInvert(mystr *source){
 const int sourceLen=getStringLen(*source);
 if(sourceLen<1)return false;
 mystr returnRef=NULL;
 returnRef=reallocStringMemory(returnRef,sourceLen+1);
 if(returnRef==NULL)return false;
 for(int i=0;i<sourceLen;i++){
  returnRef[i]=(*source)[sourceLen-i-1];
 }
 returnRef[sourceLen]=(char)STRING_END;
 freeStr(source);
 *source=returnRef;
 return true;
}

#endif
