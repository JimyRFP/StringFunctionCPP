#ifndef STRINGFUNCTIONS_INTEGER2STRING
#define STRINGFUNCTIONS_INTEGER2STRING
#include <stdlib.h>
mystr c_StringFunctions::integer2String(const int ind){
 bool isNegative=false;
 if(ind<0)isNegative=true;
 int base=abs(ind);
 int rest=0;
 mystr ret=NULL;
 char asc2Char;
 do{
  rest=base%10;
  base-=rest;
  base/=10;
  asc2Char=rest+48;
  strAdd(&ret,&asc2Char,0,1);
 }while(base!=0);
 if(isNegative){
    strAdd(&ret,(mystr)"-",0,1);
 }
 strInvert(&ret);
 return ret;
}



#endif
