#ifndef STRINGFUNCTIONS_copystr
#define STRINGFUNCTIONS_copystr

mystr c_StringFunctions::copyStr(const mystr str,int *retLen=NULL)const{
  const int len=getStringLen(str);
  mystr ret=NULL;
  if(len>0){
   ret=(mystr)malloc((len+1)*sizeof(mystr));
   if(ret==NULL)return NULL;
   for(int i=0;i<=len;i++){
    ret[i]=str[i];
   }
  }
  if(retLen!=NULL)*retLen=len;
  return ret;
}


#endif
