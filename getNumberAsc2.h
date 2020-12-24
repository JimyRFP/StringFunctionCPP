#ifndef STRINGFUNCTIONS_GETNUMBERASC2
#define STRINGFUNCTIONS_GETNUMBERASC2

char c_StringFunctions::getNumberAsc2(const int n){
 if(n<0 || n>9)return 0;
 return char(48+n);
};

#endif
