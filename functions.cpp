#include "StringFunctions.h"
mystr c_StringFunctions::trim(const mystr strC){
 const mystr clcBase="  \n\t\r";
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
