#ifndef STRINGFUNCTIONS_setString
#define STRINGFUNCTIONS_setString
#include "classbase.h"
#include <stdlib.h>
bool c_StringFunctions::setString(const mystr str){
  resetLastErro();
  size_t ind=0;
  while(*(str+ind)!=STRING_END)ind++;
  if(ind==0){
    setLastErro(STRINGFUNCTION_LASTERRO_NOCONTENT);
    return false;
  }
  m_string=allocStringMemory(ind+1);
  if(m_string==NULL)
    return false;
  for(size_t i=0;i<ind;i++){
  m_string[i]=str[i];
  }
  m_string[ind]=STRING_END;
  return true;
}

#endif // STRINGFUNCTIONS_setString
/*

PARAMS
 mystr -> Any text or char*
   //EXEMPLE
     c_StringFunctions::setString((mystr)"Any text here");
RETURN VALUE
  true -> if everything is ok.
  false -> if have any error. The error can be read with function c_StringFunctions::getLastErro()

---//HOW IT WORK//---
THIS FUNCTON WILL CREATE AN MALLOC TO PRIVATE OBJ m_string.


*/
