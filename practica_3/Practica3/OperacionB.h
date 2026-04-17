#ifndef OPERACIONB_H
#define OPERACIONB_H

unsigned char rotateLeft(unsigned char value, int shift);
unsigned char rotateRight(unsigned char value, int shift);
void xorCipherPtr(char* text, char key, int shift, bool cipher);

#endif // OPERACIONB_H
