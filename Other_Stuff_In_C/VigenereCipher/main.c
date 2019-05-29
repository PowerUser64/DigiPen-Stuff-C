/******************************
 * Filename: main.c
 * Name: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief: The test file to use with vigenereCipher.c.  You will need to set it up to take input from the console for both the string to encrypt and the key to encrypt with, please use the provided arrays!  After encrypting also test the decrypting! 
 * Brief Description: Program shows printing out a string with a pointer
   gcc -Wall -Wextra -O -ansi -pedantic -o main main.c
 ******************************/

#include <stdio.h>
#include "vigenereCipher.h"

int main(void)
{
	unsigned char string[256];
	unsigned char key[32];
	int i = 0, j = 0, passes, keylen, stringlen, method;

	/*ask for the string to encrypt and store it in string*/
	printf("\nWhat phrase do you want to encrypt?\n>");
	fgets((char *)string, 256, stdin);

	/*ask for the key to encrypt with and store it in key*/
	printf("\nWhat encryption key do you want to use?\n>");
	fgets((char *)key, 32, stdin);

	/*ask for how many passes to encrypt with*/
	printf("\nHow many passes to do?\n>");
	scanf(" %i", &passes);

	/*encrypt string with the key, make sure set to encode!*/

	/*print out the encoded string*/

	/*now reverse it back to normal by setting it to decode and print it out again*/

	/* Capital or lowercase for key and string */
	char _scase = '\0';
	char _kcase = '\0';

	printf("Encode (0) or decode (1)?\n");
	scanf(" %i", &method);

	while (getchar() != '\n')
		;

	return 0;
}