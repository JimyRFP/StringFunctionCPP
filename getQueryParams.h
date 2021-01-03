#ifndef STRINGFUNCTIONS_GETQUERYPARAMS
#define STRINGFUNCTIONS_GETQUERYPARAMS

urlQuery* c_StringFunctions::getQueryParams(const mystr str){
 size_t str_ind=0;
 bool haveQuery=false;
 while(str[str_ind]!=STRING_END){
   if(str[str_ind]==STRING_QUERY_INITPARAMS){
     haveQuery=true;
     str_ind++;
     break;
   }
   str_ind++;
 }
 if(!haveQuery){
    return NULL;
 }

 urlQuery *current,*retBase;
 retBase=createUrlQuery();
 current=retBase;
 int initInd;
 while(str[str_ind]!=STRING_END){
   initInd=str_ind;
   while(str[str_ind]!=STRING_GET_INITVALUE && str[str_ind]!=STRING_END)str_ind++;
     if(str_ind-initInd>0)
     strAdd(&current->param,&str[initInd],0,str_ind-initInd);
     if(str[str_ind]==STRING_END)break;
     str_ind++;
     initInd=str_ind;
   while(str[str_ind]!=STRING_GET_CLOSEVALUE && str[str_ind]!=STRING_END)str_ind++;
     strAdd(&current->value,&str[initInd],0,str_ind-initInd);
     if(str[str_ind]==STRING_END)break;
     str_ind++;
     if(str[str_ind]==STRING_END)break;
     current->next=createUrlQuery();
     current=current->next;
}



 return retBase;
}

void c_StringFunctions::freeUrlQuery(urlQuery* data){
  urlQuery *next,*current;
  current=data;
  while(current!=NULL){
    freeStr(&current->value);
    freeStr(&current->param);
    next=current->next;
    free(current);
    current=next;
  }
}

urlQuery* c_StringFunctions::createUrlQuery(){
 urlQuery*ret=(urlQuery*)malloc(sizeof(urlQuery));
 zeroUrlQueryStruct(ret);
 return ret;
}

#endif
