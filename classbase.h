#ifndef STRINGFUNCTIONS_CLASSBASE
#define STRINGFUNCTIONS_CLASSBASE
class c_StringFunctions{
  public:
    c_StringFunctions();
    //WORKFUNCTION
    mystr clearSpecificChar(const mystr,const char);
    mystr clearSpecificChars(const mystr,const mystr);
    mystr justLettersAndNumbers(const mystr);
    urlQuery* getQueryParams(const mystr);
    void freeUrlQuery(urlQuery*);
    mystr getUrlWithoutParams(const mystr);
    int searchString(const mystr,const mystr sea,int size);
    mystr integer2String(const int);
    bool strInvert(mystr*);
    bool strCompare(const mystr,const mystr);
    bool strCompare(const mystr,const mystr,const int len);
    mystr trim(const mystr);
    mystr trimFree(const mystr);
    mystr clearLeft(const mystr,const mystr);
    mystr clearRight(const mystr,const mystr);
    mystr strCut(const mystr,const int size);
    mystr strCutFree(const mystr,const int size);
    csvInfo* strToCsvStruct(const mystr,const char,const char);
    void zeroCsvStruct(csvInfo*);
    mystr csvStructToStr(const csvInfo*,const char,const char);
    void freeCsvStruct(csvInfo**);
    csvInfo* csvStructAdd(ENUM_CSVSTRUCT_ADD,csvInfo*,void *);
    csvInfo* csvCreateStruct();
    csvInfo* csvCopyStruct(const csvInfo*);
    void freeStr(mystr*str){
      if(*str==NULL)return;
      free(*str);
      *str=NULL;
    }
    int  string2int(char*,const int);
    void freeStrArray(mystr**str,const int);
    mystr* copyStrArray(const mystr*,const int);
    int getStringLen(const mystr)const;
    //SETFUNCTION
    bool setString(const mystr);
    //ADDSTRING
    int strAdd(mystr*,const mystr,const int);
    mystr copyStr(const mystr,int*);
    int copyNcsvInfo(csvInfo**,csvInfo*,const int);
  private:
     //GETFUNCTION
     char getNumberAsc2(const int);
     //SETINGSFUNCTION
     mystr reallocStringMemory(mystr,int size);
     void  zeroUrlQueryStruct(urlQuery* stru);
     urlQuery* createUrlQuery();
};

//CONSTRUCTOR
c_StringFunctions::c_StringFunctions(){

}


#endif

