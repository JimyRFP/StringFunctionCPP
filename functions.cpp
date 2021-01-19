#include "StringFunctions.h"
#include<stdio.h>
#include<math.h>
mystr c_StringFunctions::trim(const mystr strToTrim){
 const mystr clcBase=(mystr)"  \n\t\r";
 mystr leftCleanerRef=NULL,returnRef=NULL;
 leftCleanerRef=clearLeft(strToTrim,clcBase);
 returnRef=clearRight(leftCleanerRef,clcBase);
 free(leftCleanerRef);
 return returnRef;
}

mystr c_StringFunctions::trimFree(const mystr strToTrim){
 mystr returnRef=trim(strToTrim);
 free(strToTrim);
 return returnRef;
}

mystr c_StringFunctions::clearLeft(const mystr strToClear,const mystr charsToTake){
 int firstIndOk;
 int j,i=0;
 while(strToClear[i]!=STRING_END){
  firstIndOk=i;
  j=0;
  while(charsToTake[j]!=STRING_END){
   if(charsToTake[j]==strToClear[i]){
    firstIndOk=-1;
    break;
   }
   j++;
  }
  i++;
  if(firstIndOk>-1)break;
 }
 if(firstIndOk<0)return NULL;
 mystr ret=NULL;
 strAdd(&ret,&strToClear[firstIndOk],-1);
 return ret;
}

mystr c_StringFunctions::clearRight(const mystr toClc,const mystr clcAlg){
 const int baseLen=getStringLen(toClc);

 int firstIndOk;
 int j;
 for(int i=baseLen-1;i>=0;i--){
  firstIndOk=i;
  j=0;
  while(clcAlg[j]!=STRING_END){
   if(clcAlg[j]==toClc[i]){
    firstIndOk=-1;
    break;
   }
   j++;
  }
  if(firstIndOk>-1)break;
 }
 if(firstIndOk<0)return NULL;
 mystr ret=NULL;
 strAdd(&ret,toClc,firstIndOk+1);
 return ret;

  return NULL;
}

mystr c_StringFunctions::getUrlWithoutParams(const mystr url){
  int i=0;
  while(url[i]!=STRING_END){
    if(url[i]==STRING_QUERY_INITPARAMS)break;
    i++;
  }
  mystr ret=NULL;
  strAdd(&ret,url,i);
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
 strAdd(&ret,&base[begin],end);
 return ret;
}

mystr c_StringFunctions::strCutFree(const mystr base,const int size){
 mystr ret=strCut(base,size);
 if(ret==NULL)return base;
 free(base);
 return ret;
}

csvInfo* c_StringFunctions::strToCsvStruct(const mystr data,const char itemLineBreak,const char lineBreak){
 csvInfo *use,*ref=csvCreateStruct();
 use=ref;
 mystr tempVal;
 int initInd,i=0;
 while(data[i]!=STRING_END && (data[i]==itemLineBreak || data[i]==lineBreak))i++;
 while(data[i]!=STRING_END){
   tempVal=NULL;
   initInd=i;
   while(data[i]!=itemLineBreak && data[i]!=lineBreak && data[i]!=STRING_END)i++;
   if(i-initInd>0)
    strAdd(&tempVal,(mystr)&data[initInd],i-initInd);
   if(tempVal!=NULL){
     if(use->size<1){
      use->lineInfo=(mystr*)malloc(sizeof(mystr));
     }else{
      use->lineInfo=(mystr*)realloc(use->lineInfo,(use->size+1)*sizeof(mystr));
     }
     tempVal=trimFree(tempVal);
     use->lineInfo[use->size]=tempVal;
     use->size++;
   }
   if(data[i]==lineBreak){
    i++;
   if(data[i]==STRING_END)break;
    use->next=csvCreateStruct();
    if(use->next==NULL){
      freeCsvStruct(&ref);
      return NULL;
    }
    use=use->next;
    continue;
   }

   i++;
 }
 return ref;
}

void c_StringFunctions::zeroCsvStruct(csvInfo*info){
 info->lineInfo=NULL;
 info->next=NULL;
 info->size=0;
}

mystr c_StringFunctions::csvStructToStr(const csvInfo*info,const char itemLineBreak,const char lineBreak){
 mystr ret=NULL;
 csvInfo *ref=(csvInfo*)info;
 while(ref!=NULL){
   if(ref->lineInfo==NULL){
      ref=ref->next;
      continue;
   }
   for(size_t i=0;i<ref->size;i++){
     strAdd((mystr*)&ret,ref->lineInfo[i],-1);
     strAdd((mystr*)&ret,(mystr)&itemLineBreak,1);
   }
   ret=strCutFree(ret,1);
   strAdd(&ret,(mystr)&lineBreak,1);
   ref=ref->next;
 }
 return ret;
}

void c_StringFunctions::freeCsvStruct(csvInfo**info){
  csvInfo *next,*base=*info;
  *info=NULL;
  while(base!=NULL){
    freeStrArray(&base->lineInfo,base->size);
    next=base->next;
    free(base);
    base=next;
  }
}

csvInfo* c_StringFunctions::csvStructAdd(ENUM_CSVSTRUCT_ADD addInfo,csvInfo* strRef,void *addData){
 csvInfo *ret=NULL;
 if(strRef==NULL)return NULL;
 switch(addInfo){
  case CSVSTRUCT_ADD_LINEDATA:
    ret=strRef;
    if(strRef->size<1){
      strRef->lineInfo=(mystr*)malloc(sizeof(mystr));
    }else{
      strRef->lineInfo=(mystr*)realloc(strRef->lineInfo,(strRef->size+1)*sizeof(mystr));
    }
    if(strRef->lineInfo==NULL)return NULL;
    strRef->lineInfo[strRef->size]=copyStr((mystr)addData,NULL);
    strRef->size++;
    break;
  case CSVSTRUCT_ADD_NEWLINE:
    if(strRef->next!=NULL)return NULL;
    strRef->next=csvCreateStruct();
    if(strRef->next==NULL)return NULL;
    ret=strRef->next;
    break;
  default:
    return NULL;
 };
 return ret;
}

csvInfo* c_StringFunctions::csvCreateStruct(){
 csvInfo *ret=NULL;
 ret=(csvInfo*)malloc(sizeof(csvInfo));
 zeroCsvStruct(ret);
 return ret;
}


csvInfo* c_StringFunctions::csvCopyStruct(const csvInfo*base){
 if(base==NULL)return NULL;
 csvInfo*ret=csvCreateStruct();
 if(ret==NULL)return NULL;
 ret->lineInfo=copyStrArray(base->lineInfo,base->size);
 ret->next=base->next;
 ret->size=base->size;
 return ret;
}

mystr* c_StringFunctions::copyStrArray(const mystr*base,const int size){
 mystr *ret=NULL;
 if(base==NULL)return NULL;
 if(size<1)return NULL;
 ret=(mystr*)malloc(size*sizeof(mystr));
 for(int i=0;i<size;i++){
  ret[i]=copyStr(base[i],NULL);
 }
 return ret;
}

void c_StringFunctions::freeStrArray(mystr **str,const int size){
 if(*str==NULL)return;
 for(int i=0;i<size;i++){
   free((*str)[i]);
 }
 free(*str);
 *str=NULL;
}

int c_StringFunctions::copyNcsvInfo(csvInfo**ref,csvInfo*base,const int ncopy){
 if(ncopy<1)return 0;
 if(base==NULL)return 0;
 csvInfo *copyBase=base;
  int cncopy=0;
 if(*ref==NULL){
    *ref=csvCopyStruct(base);
    if(*ref==NULL)return 0;
    copyBase=copyBase->next;
    (*ref)->next=NULL;
    cncopy++;
 }
 csvInfo *lastAdd=*ref;
 while(lastAdd!=NULL){
    if(lastAdd->next==NULL)break;
    lastAdd=lastAdd->next;
 }
 copyBase=base;


 while(copyBase!=NULL){
  if(cncopy>=ncopy)break;
  lastAdd->next=csvCopyStruct(copyBase);
  if(lastAdd->next==NULL){
    freeCsvStruct(ref);
    return 0;
  }
  lastAdd=lastAdd->next;
  copyBase=copyBase->next;
  cncopy++;
 }
 if(lastAdd!=NULL)
  lastAdd->next=NULL;
 return cncopy;
};

int c_StringFunctions::string2int(char*base,const int size=-1){
  const int len=getStringLen(base);
  if(len<1)return 0;
  int useLen=len;
  if(size>0)
     if(size<useLen)
          useLen=size;
  int baseInt,ret=0;
  int i=0;
  bool isNegative=false;
  if(base[i]=='-'){
    i++;
    isNegative=true;
  }
  for(;i<useLen;i++){
    baseInt=(int)(base[i]-48);
    baseInt%=10;
    ret+=baseInt*pow(10,useLen-i-1);
  }
  if(isNegative)ret*=-1;
  return ret;
}


mystr c_StringFunctions::clearSpecificChar(mystr str,const char chr){
  if(str==NULL)return NULL;
  const int len=getStringLen(str);
  if(len<1)return NULL;
  mystr ret=(mystr)malloc((len+1)*sizeof(char));
  int nadd=0;
  for(int i=0;i<len;i++){
    if(str[i]==chr)continue;
    ret[nadd]=str[i];
    nadd++;
  }
  if(nadd==0){
    freeStr(&ret);
    return NULL;
  }
  ret[nadd+1]=STRING_END;
  if(nadd==len)return ret;
  ret=(mystr)realloc(ret,(nadd+1)*sizeof(char));
  return ret;
}

mystr c_StringFunctions::clearSpecificChars(mystr str,const mystr clr){
  if(str==NULL || clr==NULL)return NULL;
  const int strLen=getStringLen(str);
  const int clrLen=getStringLen(clr);
  if(strLen<1 || clrLen<1)return NULL;
  mystr ret=(mystr)malloc((strLen+1)*sizeof(char));
  int nadd=0;
  bool gone=false;
  for(int i=0;i<strLen;i++){
    gone=false;
    for(int j=0;j<clrLen;j++){
      if(str[i]==clr[j]){
        gone=true;
        break;
      }
    }
    if(gone)continue;
    ret[nadd]=str[i];
    nadd++;
  }
  if(nadd==0){
    freeStr(&ret);
    return NULL;
  }
  ret[nadd+1]=STRING_END;
  if(nadd==strLen)return ret;
  ret=(mystr)realloc(ret,(nadd+1)*sizeof(char));
  return ret;
}


mystr c_StringFunctions::justLettersAndNumbers(const mystr base){
 if(base==NULL)return NULL;
 const int len=getStringLen(base);
 if(len<1)return NULL;
 mystr ret=(mystr)malloc((len+1)*sizeof(char));
 int nadd=0;
 for(int i=0;i<len;i++){
   if((base[i]<'0' || base[i]>'9') &&
      (base[i]<'A' || base[i]>'Z') &&
      (base[i]<'a' || base[i]>'z')
      )continue;
   ret[nadd]=base[i];
   nadd++;
 }
  if(nadd==0){
    freeStr(&ret);
    return NULL;
  }
  ret[nadd]=STRING_END;
  if(nadd==len)return ret;
  ret=(mystr)realloc(ret,(nadd+1)*sizeof(char));

  return ret;
}

