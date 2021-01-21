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
 if(strToClear==NULL || charsToTake==NULL)return NULL;
 int firstValidInd=-1;
 int j,i=0;
 while(strToClear[i]!=STRING_END){
  firstValidInd=i;
  j=0;
  while(charsToTake[j]!=STRING_END){
   if(charsToTake[j]==strToClear[i]){
    firstValidInd=-1;
    break;
   }
   j++;
  }
  i++;
  if(firstValidInd>-1)break;
 }
 if(firstValidInd<0)return NULL;
 mystr returnRef=NULL;
 strAdd(&returnRef,&strToClear[firstValidInd],-1);
 return returnRef;
}

mystr c_StringFunctions::clearRight(const mystr strToClear,const mystr charsToTake){
 if(strToClear==NULL || charsToTake==NULL)return NULL;
 const int strToClearLen=getStringLen(strToClear);
 int lastValidInd=-1;
 int j;
 for(int i=strToClearLen-1;i>=0;i--){
  lastValidInd=i;
  j=0;
  while(charsToTake[j]!=STRING_END){
   if(charsToTake[j]==strToClear[i]){
    lastValidInd=-1;
    break;
   }
   j++;
  }
  if(lastValidInd>-1)break;
 }
 if(lastValidInd<0)return NULL;
 mystr returnRef=NULL;
 strAdd(&returnRef,strToClear,lastValidInd+1);
 return returnRef;
}

mystr c_StringFunctions::getUrlWithoutParams(const mystr url){
  int returnSize=0;
  while(url[returnSize]!=STRING_END){
    if(url[returnSize]==STRING_QUERY_INITPARAMS)break;
    returnSize++;
  }
  mystr returnRef=NULL;
  strAdd(&returnRef,url,returnSize);
  return returnRef;
}

mystr c_StringFunctions::strCut(const mystr strToCut,const int size){
 int newStrInit;
 int newStrEnd;
 if(size>0){
  newStrInit=0;
  newStrEnd=getStringLen(strToCut)-size;
 }else if(size<0){
  newStrInit=-size;
  newStrEnd=getStringLen(strToCut);
  if(newStrEnd<=newStrInit)return NULL;
 }else{
  return NULL;
 }
 if(newStrEnd<=0)return NULL;

 mystr returnRef=NULL;
 strAdd(&returnRef,&strToCut[newStrInit],newStrEnd);
 return returnRef;
}

mystr c_StringFunctions::strCutFree(const mystr strToCut,const int size){
 mystr returnRef=strCut(strToCut,size);
 if(returnRef==NULL)return strToCut;
 free(strToCut);
 return returnRef;
}

csvInfo* c_StringFunctions::strToCsvStruct(const mystr dataToConvert,const char itemLineBreak,const char lineBreak){
 csvInfo *currentRef,*returnRef=csvCreateStruct();
 currentRef=returnRef;
 mystr tempStr;
 int strInitInd,i=0;
 while(dataToConvert[i]!=STRING_END && (dataToConvert[i]==itemLineBreak || dataToConvert[i]==lineBreak))i++;
 while(dataToConvert[i]!=STRING_END){
   tempStr=NULL;
   strInitInd=i;
   while(dataToConvert[i]!=itemLineBreak && dataToConvert[i]!=lineBreak && dataToConvert[i]!=STRING_END)i++;
   if(i-strInitInd>0)
    strAdd(&tempStr,(mystr)&dataToConvert[strInitInd],i-strInitInd);
   if(tempStr!=NULL){
     if(currentRef->size<1){
      currentRef->lineInfo=(mystr*)malloc(sizeof(mystr));
      currentRef->size=0;
     }else{
      currentRef->lineInfo=(mystr*)realloc(currentRef->lineInfo,(currentRef->size+1)*sizeof(mystr));
     }
     if(currentRef->lineInfo==NULL){
        freeCsvStruct(&returnRef);
        return NULL;
     }
     tempStr=trimFree(tempStr);
     currentRef->lineInfo[currentRef->size]=tempStr;
     currentRef->size++;
   }
   if(dataToConvert[i]==lineBreak){
    i++;
    if(dataToConvert[i]==STRING_END)break;
    currentRef->next=csvCreateStruct();
    if(currentRef->next==NULL){
      freeCsvStruct(&returnRef);
      return NULL;
    }
    currentRef=currentRef->next;
    continue;
   }

   i++;
 }
 return returnRef;
}

void c_StringFunctions::zeroCsvStruct(csvInfo*info){
 if(info==NULL)return;
 info->lineInfo=NULL;
 info->next=NULL;
 info->size=0;
}

mystr c_StringFunctions::csvStructToStr(const csvInfo*csvToConvert,const char itemLineBreak,const char lineBreak){
 mystr strReturnRef=NULL;
 csvInfo *currentCsvRef=(csvInfo*)csvToConvert;
 while(currentCsvRef!=NULL){
   if(currentCsvRef->lineInfo==NULL){
      currentCsvRef=currentCsvRef->next;
      continue;
   }
   for(size_t i=0;i<currentCsvRef->size;i++){
     strAdd((mystr*)&strReturnRef,currentCsvRef->lineInfo[i],-1);
     strAdd((mystr*)&strReturnRef,(mystr)&itemLineBreak,1);
   }
   strReturnRef=strCutFree(strReturnRef,1);
   strAdd(&strReturnRef,(mystr)&lineBreak,1);
   currentCsvRef=currentCsvRef->next;
 }
 return strReturnRef;
}

void c_StringFunctions::freeCsvStruct(csvInfo**csvToFree){
  if(*csvToFree==NULL)return;
  csvInfo *nextCsvRef,*currentCsvRef=*csvToFree;
  *csvToFree=NULL;
  while(currentCsvRef!=NULL){
    freeStrArray(&currentCsvRef->lineInfo,currentCsvRef->size);
    nextCsvRef=currentCsvRef->next;
    free(currentCsvRef);
    currentCsvRef=nextCsvRef;
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
 csvInfo *returnRef=NULL;
 returnRef=(csvInfo*)malloc(sizeof(csvInfo));
 zeroCsvStruct(returnRef);
 return returnRef;
}


csvInfo* c_StringFunctions::csvCopyStruct(const csvInfo*source){
 if(source==NULL)return NULL;
 csvInfo*ret=csvCreateStruct();
 if(ret==NULL)return NULL;
 ret->lineInfo=copyStrArray(source->lineInfo,source->size);
 ret->next=source->next;
 ret->size=source->size;
 return ret;
}

mystr* c_StringFunctions::copyStrArray(const mystr*source,const int size){
 mystr *returnRef=NULL;
 if(source==NULL)return NULL;
 if(size<1)return NULL;
 returnRef=(mystr*)malloc(size*sizeof(mystr));
 for(int i=0;i<size;i++){
  returnRef[i]=copyStr(source[i],NULL);
 }
 return returnRef;
}

void c_StringFunctions::freeStrArray(mystr **str,const int size){
 if(*str==NULL)return;
 for(int i=0;i<size;i++){
   free((*str)[i]);
 }
 free(*str);
 *str=NULL;
}

int c_StringFunctions::copyNcsvInfo(csvInfo**destination,csvInfo*source,const int ncopy){
 if(ncopy<1)return 0;
 if(source==NULL)return 0;
 csvInfo *sourceLastRef=source;
  int cncopy=0;
 if(*destination==NULL){
    *destination=csvCopyStruct(source);
    if(*destination==NULL)return 0;
    sourceLastRef=sourceLastRef->next;
    (*destination)->next=NULL;
    cncopy++;
 }
 csvInfo *destinationLastRef=*destination;
 while(destinationLastRef!=NULL){
    if(destinationLastRef->next==NULL)break;
    destinationLastRef=destinationLastRef->next;
 }

 while(sourceLastRef!=NULL){
  if(cncopy>=ncopy)break;
  destinationLastRef->next=csvCopyStruct(sourceLastRef);
  if(destinationLastRef->next==NULL){
    freeCsvStruct(destination);
    return 0;
  }
  destinationLastRef=destinationLastRef->next;
  sourceLastRef=sourceLastRef->next;
  cncopy++;
 }
 if(destinationLastRef!=NULL)
  destinationLastRef->next=NULL;
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

