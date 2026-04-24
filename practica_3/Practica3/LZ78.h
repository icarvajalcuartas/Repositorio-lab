#ifndef LZ78_H
#define LZ78_H

char* compressLZ78(const char* input,bool desc, char* &compressed,int &tam);
bool comparacion(char* descomprimido,const char *input,bool des);
#endif // LZ78_H
