#ifndef STRINGFUNCTIONS_CLASSBASE
#define STRINGFUNCTIONS_CLASSBASE
class c_StringFunctions{
  public:
    c_StringFunctions();
    //WORKFUNCTION
    bool clearSpecificString(const mystr);
    urlQuery* getQueryParams(const mystr);
    void freeUrlQuery(urlQuery*);
    mystr getUrlWithoutParams(const mystr);
    int searchString(const mystr,const mystr sea,int size);
    mystr integer2String(const int);
    bool strInvert(mystr*);
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
      free(*str);
      *str=NULL;
    }
    mystr* copyStrArray(const mystr*,const int);
    //GETFUNCTIONS
    mystr getString();
    int getStringLen()const{return getStringLen(m_string);};
    int getStringLen(const mystr)const;
    STRINGFUNCTION_LASTERRO getLastErro()const{return m_lasterro;}
    //SETFUNCTION
    bool setString(const mystr);
    //ADDSTRING
    int strAdd(mystr*,const mystr,const int,const int);
    mystr copyStr(const mystr)const;
  private:
   //OBJECTS
   mystr m_string;
   STRINGFUNCTION_LASTERRO m_lasterro;
   //FUNCTIONS
     //SETFUNCTIONS
     void setLastErro(STRINGFUNCTION_LASTERRO lasterro){m_lasterro=lasterro;}
     void resetLastErro(){m_lasterro=STRINGFUNCTION_LASTERRO_NOERRO;}
     //GETFUNCTION
     char getNumberAsc2(const int);
     //SETINGSFUNCTION
     mystr allocStringMemory(int size);
     mystr reallocStringMemory(mystr,int size);
     void  zeroUrlQueryStruct(urlQuery* stru){
      stru->param=NULL;
      stru->value=NULL;
      stru->next=NULL;
     }
     urlQuery* createUrlQuery();
};

//CONSTRUCTOR
c_StringFunctions::c_StringFunctions(){
 m_string=NULL;
}


#endif

