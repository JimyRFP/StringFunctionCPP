#ifndef STRINGFUNCTIONS_getStringLen
#define STRINGFUNCTIONS_getStringLen
#include "classbase.h"



int c_StringFunctions::getStringLen(mystr str)const{
    int ind=0;
    if(str==NULL)
      return 0;
    while(str[ind]!=STRING_END){
      ind++;
    }
    return ind;
}

#endif // STRINGFUNCTIONS_getStringLen
/*
--//PARAMS//--
 mystr->"Any String"

--//EXEMPLE//--
c_StringFunctions::getStringLen((mystr)"any value here")

--//RETURN VALUE//--
int >0 -> The string size.
#define STRINGIND_ERRO -> Error. The error can be read with function c_StringFunctions::getLastErro()

---//HOW IT WORK//---
This function will return the size of the string.
*/


