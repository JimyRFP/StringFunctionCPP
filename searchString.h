#ifndef STRINGFUNCTIONS_serchString
#define STRINGFUNCTIONS_serchString
int c_StringFunctions::searchString(const mystr base,const mystr sea,int size=-1){
  const int baseLen=getStringLen(base);
  int seaLen=getStringLen(sea);
  if(size>0){
   seaLen=seaLen>size?size:seaLen;
  }
  if(seaLen<1)return -1;
  int j;
  for(int i=0;i<baseLen;i++){
    if(i+seaLen>baseLen)return -1;
    for(j=0;j<seaLen;j++){
      if(base[i+j]!=sea[j])break;
    }
    if(j==seaLen)return i;
    i+=j;
  }
  return -1;

}


#endif
