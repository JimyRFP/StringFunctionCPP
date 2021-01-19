#ifndef STRINGFUNCTIONS_STRCOMPARE
#define STRINGFUNCTIONS_STRCOMPARE
bool c_StringFunctions::strCompare(const mystr str1,const mystr str2){
  if(str1==NULL || str2==NULL)return false;
  int i=0;
  while(str1[i]!=STRING_END && str2[i]!=STRING_END){
    if(str1[i]!=str2[i])return false;
    i++;
  }
  if(str1[i]==STRING_END && str2[i]==STRING_END)return true;
  return false;
}

bool c_StringFunctions::strCompare(const mystr str1,const mystr str2,const int len){
  if(str1==NULL || str2==NULL)return false;
  int i=0;
  while(str1[i]!=STRING_END && str2[i]!=STRING_END){
    if(str1[i]!=str2[i])return false;
    i++;
    if(i==len)return true;
  }
  if(str1[i]==STRING_END && str2[i]==STRING_END)return true;
  return false;
}
#endif
