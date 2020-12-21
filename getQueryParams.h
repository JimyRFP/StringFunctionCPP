#ifndef STRINGFUNCTIONS_GETQUERYPARAMS
#define STRINGFUNCTIONS_GETQUERYPARAMS

size_t c_StringFunctions::getQueryParams(const mystr str,urlQuery** ret){
 const size_t strLen=getStringLen(str);
 if(strLen<1)return 0;
 size_t str_ind=0;
 bool haveQuery=false;
 while(str_ind<strLen){
   if(str[str_ind]==STRING_QUERY_INITPARAMS){
     haveQuery=true;
     str_ind++;
     break;
   }
   str_ind++;
 }
 if(!haveQuery)return 0;
 size_t nParams=0;
 urlQuery *query;
 query=(urlQuery*)malloc(1*sizeof(urlQuery));

 while(str_ind<strLen){
   zeroUrlQueryStruct(&query[nParams]);
   while(str[str_ind]!=STRING_GET_INITVALUE && str_ind<strLen){
     if(strAdd(&(query[nParams].param),&str[str_ind],0,1)<1)return 0;
     str_ind++;
   }
     str_ind++;
   while(str[str_ind]!=STRING_GET_CLOSEVALUE && str_ind<strLen){
     if(strAdd(&(query[nParams].value),&str[str_ind],0,1)<1)return 0;
     str_ind++;
   }
     nParams++;
     str_ind++;
     if(str_ind<strLen){
       query=(urlQuery*)realloc(query,(nParams+1)*sizeof(urlQuery));
       if(query==NULL)return 0;
     }
 }
 *ret=query;
 return nParams;
}


#endif
