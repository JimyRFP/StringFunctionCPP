#ifndef STRINGFUNCTIONS_strAdd
#define STRINGFUNCTIONS_strAdd
/*int c_StringFunctions::strAdd(mystr* dst,const mystr src,const int init=0,int size=-1){
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
*/
int c_StringFunctions::strAdd(mystr* dst,const mystr src,const int size=-1){
 int addSize=0;
 while(src[addSize]!=STRING_END)addSize++;
 if(size>0){
    if(addSize>size)addSize=size;
 }
 int oldSize;
 mystr ret;
 ret=copyStr(*dst,&oldSize);
 ret=reallocStringMemory(ret,oldSize+addSize+1);
 if(ret==NULL)return 0;

 for(int i=0;i<addSize;i++){
    ret[oldSize+i]=src[i];
 }
 ret[oldSize+addSize]=STRING_END;
 freeStr(dst);
 *dst=ret;
 return oldSize+addSize;
}


#endif
