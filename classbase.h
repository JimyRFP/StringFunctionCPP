#ifndef STRINGFUNCTIONS_CLASSBASE
#define STRINGFUNCTIONS_CLASSBASE
class c_StringFunctions{
  public:
    c_StringFunctions();
    //WORKFUNCTION
    bool clearSpecificString(const mystr);
    //GETFUNCTIONS
    mystr getString();
    int getStringLen()const{return getStringLen(m_string);};
    int getStringLen(const mystr)const;
    STRINGFUNCTION_LASTERRO getLastErro()const{return m_lasterro;}
    //SETFUNCTION
    bool setString(const mystr);

  private:
   //OBJECTS
   mystr m_string;
   STRINGFUNCTION_LASTERRO m_lasterro;
   //FUNCTIONS
     //SETFUNCTIONS
     void setLastErro(STRINGFUNCTION_LASTERRO lasterro){m_lasterro=lasterro;}
     void resetLastErro(){m_lasterro=STRINGFUNCTION_LASTERRO_NOERRO;}
     //GETFUNCTION

     //SETINGSFUNCTION
     mystr allocStringMemory(int size);
};

//CONSTRUCTOR
c_StringFunctions::c_StringFunctions(){
 m_string=NULL;
}


#endif

