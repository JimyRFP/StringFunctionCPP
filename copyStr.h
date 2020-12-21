#ifndef STRINGFUNCTIONS_copystr
#define STRINGFUNCTIONS_copystr

mystr c_StringFunctions::copyStr(const mystr str)const{
  const int len=getStringLen(str);
  if(len<1)return NULL;
  mystr ret=(mystr)malloc((len+1)*sizeof(mystr));
  if(ret==NULL)return NULL;
  for(int i=0;i<=len;i++){
   ret[i]=str[i];
  }
  return ret;
}


#endif
