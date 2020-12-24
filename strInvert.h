#ifndef STRINGFUNCTIONS_STRINVERT
#define STRINGFUNCTIONS_STRINVERT
bool c_StringFunctions::strInvert(mystr *base){
 const int size=getStringLen(*base);
 if(size<1)return false;
 mystr ret=allocStringMemory(size+1);
 if(ret==NULL)return false;
 for(int i=0;i<size;i++){
  ret[i]=(*base)[size-i-1];
 }
 ret[size]=(char)STRING_END;
 free(*base);
 *base=ret;
 return true;
}

#endif
