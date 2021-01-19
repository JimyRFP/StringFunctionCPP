#ifndef STRINGFUNCTIONS_strAdd
#define STRINGFUNCTIONS_strAdd
int c_StringFunctions::strAdd(mystr* destination,const mystr source,const int size=-1){
 int addSize=0;
 if(source==NULL)return 0;
 while(source[addSize]!=STRING_END)addSize++;
 if(size>0){
    if(addSize>size)addSize=size;
 }
 int oldSize=0;
 if((*destination)!=NULL)
  while((*destination)[oldSize]!=STRING_END)oldSize++;
 *destination=(mystr)reallocStringMemory(*destination,oldSize+addSize+1);

 if(*destination==NULL)return 0;
 for(int i=0;i<addSize;i++){
    (*destination)[oldSize+i]=source[i];
 }
 (*destination)[oldSize+addSize]=STRING_END;
 return oldSize+addSize;
}


#endif
