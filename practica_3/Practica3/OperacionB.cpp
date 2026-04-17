#include "OperacionB.h"

unsigned char rotateLeft(unsigned char value, int shift){
    return (value << shift) | (value >> (8 - shift));
}
unsigned char rotateRight(unsigned char value, int shift){
    return (value >> shift) | (value << (8 - shift));
}
void xorCipherPtr(char* text, char key, int shift,bool cipher){
    if(cipher){
        for (int i = 0; text[i] != '\0'; i++) {
            text[i]=(unsigned char)(text[i]);
            text[i]=rotateLeft(text[i],shift);
            text[i] = text[i] ^ key;
        }
    }
    else{
        for (int i = 0; text[i] != '\0'; i++) {
            text[i]=(unsigned char)(text[i]);
            text[i] = text[i] ^ key;
            text[i]=rotateRight(text[i],shift);

        }
    }

}
