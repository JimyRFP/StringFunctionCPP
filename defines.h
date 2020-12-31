#ifndef STRINGFUNCTIONS_DEFINES
#define STRINGFUNCTIONS_DEFINES
#include <stddef.h>
#include <stdlib.h>
typedef char* mystr;
#define STRINGIND_ERRO -1
#define STRING_END 0
#define STRING_SPACE ' '
#define STRING_TAB  '   '
#define STRING_ENDL '\n'

#define STRING_QUERY_INITPARAMS 63
#define STRING_GET_INITVALUE 61
#define STRING_GET_CLOSEVALUE 38
//LASTERRO
typedef enum ENUM_STRINGFUNCTION_LASTERRO{
  STRINGFUNCTION_LASTERRO_NOERRO=0,
  STRINGFUNCTION_LASTERRO_PTRNULL,
  STRINGFUNCTION_LASTERRO_NOCONTENT,
  STRINGFUNCTION_LASTERRO_FILTERNOCONTENT,
  STRINGFUNCTION_LASTERRO_MALLOCERROR,
}STRINGFUNCTION_LASTERRO;

typedef struct STRINGFUNCTION_QUERY{
 mystr param;
 mystr value;
 size_t size_param;
 size_t size_value;
}urlQuery;

typedef struct fc_csv_info{
 mystr *lineInfo;
 size_t size;
 fc_csv_info* next;
}csvInfo;

enum ENUM_CSVSTRUCT_ADD{
  CSVSTRUCT_ADD_LINEDATA,
  CSVSTRUCT_ADD_NEWLINE,
};

#endif // STRINGFUNCTIONS_DEFINES

