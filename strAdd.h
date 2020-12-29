#ifndef STRINGFUNCTIONS_strAdd
#define STRINGFUNCTIONS_strAdd
int c_StringFunctions::strAdd(mystr* dst,const mystr src,int init=0,int size=-1){
  int b_init=init>0?init:0;
  int len=getStringLen(src)-b_init;
  if(len<1)return 0;
  if(size>0){
   len=len>size?size:len;
  }
  int oldLen=getStringLen(*dst);
  oldLen=oldLen>=0?oldLen:0;
  mystr newStr=copyStr(*dst);
  newStr=reallocStringMemory(newStr,oldLen+len+1);
  if(newStr==NULL){
    return 0;
  }
  for(int i=0;i<len;i++){
   newStr[oldLen+i]=src[i+b_init];
  }
  newStr[oldLen+len]=STRING_END;
  if(*dst!=NULL)free(*dst);
  *dst=newStr;
  return oldLen+len;
}



#endif
