#ifndef STRINGFUNCTIONS_copystr
#define STRINGFUNCTIONS_copysource

mystr c_StringFunctions::copyStr(const mystr source,int *returnRefLen=NULL){
  const int sourceLen=getStringLen(source);
  mystr returnRef=NULL;
  if(sourceLen>0){
   returnRef=reallocStringMemory(returnRef,(int)(sourceLen+1));
   if(returnRef==NULL)return NULL;
   for(int i=0;i<=sourceLen;i++){
    returnRef[i]=source[i];
   }
  }
  if(returnRefLen!=NULL)*returnRefLen=sourceLen;
  return returnRef;
}


#endif
