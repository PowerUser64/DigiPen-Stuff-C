/****************
vigenereCipher.h
By:Ryan Scheppler
Date: 1/15/18
Brief: the header file to use with vigenereCipher.c
****************/

enum CODE_METHOD {ENCODE, DECODE};

void vigenere(unsigned char *string, unsigned char *key, enum CODE_METHOD method, int passes);