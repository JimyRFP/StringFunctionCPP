#include "StringFunctions.h"
mystr c_StringFunctions::trim(const mystr strC){
 const mystr clcBase=(mystr)"  \n\t\r";
 mystr left=NULL,ret=NULL;
 left=clearLeft(strC,clcBase);
 ret=clearRight(left,clcBase);
 free(left);
 return ret;
}

mystr c_StringFunctions::trimFree(const mystr strC){
 mystr ret=trim(strC);
 free(strC);
 return ret;
}

mystr c_StringFunctions::clearLeft(const mystr toClc,const mystr clcAlg){
 const int baseLen=getStringLen(toClc);
 const int clcLen=getStringLen(clcAlg);

 int firstIndOk;
 for(int i=0;i<baseLen;i++){
  firstIndOk=i;
  for(int j=0;j<clcLen;j++){
   if(clcAlg[j]==toClc[i]){
    firstIndOk=-1;
    break;
   }
  }
  if(firstIndOk>-1)break;
 }
 if(firstIndOk==-1)return NULL;
 mystr ret=NULL;
 strAdd(&ret,toClc,firstIndOk,-1);
 return ret;
}

mystr c_StringFunctions::clearRight(const mystr toClc,const mystr clcAlg){
 const int baseLen=getStringLen(toClc);
 const int clcLen=getStringLen(clcAlg);

 int firstIndOk;
 for(int i=baseLen-1;i>=0;i--){
  firstIndOk=i;
  for(int j=0;j<clcLen;j++){
   if(clcAlg[j]==toClc[i]){
    firstIndOk=-1;
    break;
   }
  }
  if(firstIndOk>-1)break;
 }
 if(firstIndOk==-1)return NULL;
 mystr ret=NULL;
 strAdd(&ret,toClc,0,firstIndOk+1);
 return ret;

  return NULL;
}

mystr c_StringFunctions::getUrlWithoutParams(const mystr url){
 const int len=getStringLen(url);
 if(len<1)return NULL;
 int i;
 for(i=0;i<len;i++){
    if(url[i]==STRING_QUERY_INITPARAMS)break;
 }
 mystr ret=NULL;
 strAdd(&ret,url,0,i);
 return ret;
}

mystr c_StringFunctions::strCut(const mystr base,const int size){
 int begin;
 int end;
 if(size>0){
  begin=0;
  end=getStringLen(base)-size;
 }else if(size<0){
  begin=-size;
  end=getStringLen(base);
  if(end<=begin)return NULL;
 }else{
  return NULL;
 }
 if(end<=0)return NULL;

 mystr ret=NULL;
 strAdd(&ret,base,begin,end);
 return ret;
}
