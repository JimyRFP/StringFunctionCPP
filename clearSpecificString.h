#ifndef STRINGFUNCTIONS_clearSpecificString
#define STRINGFUNCTIONS_clearSpecificString
#include "classbase.h"

bool c_StringFunctions::clearSpecificString(const mystr filter){
  resetLastErro();
  const size_t filterLen=getStringLen(filter);
  if(filterLen<1){
    setLastErro(STRINGFUNCTION_LASTERRO_FILTERNOCONTENT);
    return 0;
  }
  const size_t baseLen=getStringLen();
  if(baseLen<1){
    setLastErro(STRINGFUNCTION_LASTERRO_NOCONTENT);
    return 0;
  }
  if(filterLen>baseLen)return 0;
  mystr basestr=getString();
  mystr newstr=allocStringMemory(baseLen+1);
  bool filterok=false;
  size_t nNoFilterChar=0;

  for(size_t i=0;i<baseLen;i++){ //START FILTER
    filterok=false;
    if(i+filterLen<=baseLen){ //COMPARE STOP
      filterok=true;
      for(size_t j=0;j<filterLen;j++){
        if(basestr[i+j]!=filter[j]){
          filterok=false;
          break;
        }
      }
    }else{
      for(;i<baseLen;i++){
       newstr[nNoFilterChar]=basestr[i];
       nNoFilterChar++;
      }
      break;
    }
    if(filterok){
      i+=(filterLen-1);
      continue;
    }
    newstr[nNoFilterChar]=basestr[i];
    nNoFilterChar++;
  }
  newstr[nNoFilterChar]=0;
  if(nNoFilterChar){
    setString(newstr);
  }
  return nNoFilterChar;
}



#endif
