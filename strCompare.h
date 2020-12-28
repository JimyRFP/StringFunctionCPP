#ifndef STRINGFUNCTIONS_STRCOMPARE
#define STRINGFUNCTIONS_STRCOMPARE
bool c_StringFunctions::strCompare(const mystr str1,const mystr str2,const int len=-1){
  const int len1=getStringLen(str1);
  const int len2=getStringLen(str2);
  int verLen;
  if(len>0){
    if(len1<len || len2<len)return false;
    verLen=len;
  }else{
    if(len1!=len2 || len1<1)return false;
    verLen=len1;
  }
  for(int i=0;i<verLen;i++){
    if(str1[i]!=str2[i])return false;
  }
  return true;
}

#endif
