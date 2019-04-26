/****************
main.c
By:
Date: 
Brief: The test file to use with vigenereCipher.c.  You will need to set it up to take input from the console for both the string to encrypt and the key to encrypt with, please use the provided arrays!  After encrypting also test the decrypting! 
gcc -O -Wall -Wextra -ansi -pedantic -o vcipher vigenereCipher.c main.c
****************/
#include <stdio.h>
#include "vigenereCipher.h"

int main(void)
{
	unsigned char string[256];
	unsigned char key[32];
	int passes;
	
	/*ask for the string to encrypt and store it in string*/
	
	
	/*ask for the key to encrypt with and store it in key*/
	
	
	/*ask for how many passes to encrypt with*/
	
	
	/*encrypt string with the key, make sure set to encode!*/
	
	/*print out the encoded string*/
	
	/*now reverse it back to normal by setting it to decode and print it out again*/

	return 0;
}