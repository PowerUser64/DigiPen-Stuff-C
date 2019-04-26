/******************************
 * Filename: main.c
 * Name: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief: The test file to use with vigenereCipher.c.  You will need to set it up to take input from the console for both the string to encrypt and the key to encrypt with, please use the provided arrays!  After encrypting also test the decrypting! 
 * Brief Description: USELESS - I just have this here so my teacher can grade the main function.
   gcc -O -Wall -Wextra -ansi -pedantic -o vcipher vigenereCipher.c main.c
 ******************************/
#include "vigenereCipher.h"

void vigenere(unsigned char *string, unsigned char *key, enum CODE_METHOD method, int passes)
{
	if (method == ENCODE)
	{
		/*ask for the string to encrypt and store it in string*/
		printf("\nWhat phrase do you want to encrypt?\n>");
		fgets((char *)string, 256, stdin);
		/*ask for the key to encrypt with and store it in key*/
		printf("\nWhat encryption key do you want to use?\n>");
		fgets((char *)key, 32, stdin);

		/*ask for how many passes to encrypt with*/
		printf("\nHow many passes to do?\n>");
		scanf(" %i", &passes);
		stringlen = strlen((char *)string);
		keylen = strlen((char *)key);
		/*encrypt string with the key, make sure set to encode!*/
		/* deal with capital and lowercase letters */

		/*KILL ALL CAPITAL LETTERS*/
		for (i = 0; i < stringlen; ++i)
				string[i % stringlen] -= 32;

		for (j = 0; j < passes; ++j)
			for (i = 0; i < stringlen; string[i % stringlen] += key[i % keylen], ++i)
				;

		if (i != -1)
			printf("The encrypted phrase is:\n%s", string);
	}
	else if (method == ENCODE)
	{
		/*ask for the string to encrypt and store it in string*/
		printf("\nWhat phrase do you want to encrypt?\n>");
		fgets((char *)string, 256, stdin);
		/*ask for the key to encrypt with and store it in key*/
		printf("\nWhat encryption key do you want to use?\n>");
		fgets((char *)key, 32, stdin);

		/*ask for how many passes to encrypt with*/
		printf("\nHow many passes to do?\n>");
		scanf(" %i", &passes);
		stringlen = strlen((char *)string);
		keylen = strlen((char *)key);
		/*encrypt string with the key, make sure set to encode!*/
		/* deal with capital and lowercase letters */

		/*KILL ALL CAPITAL LETTERS*/
		for (i = 0; i < stringlen; ++i)
				string[i % stringlen] -= 32;

		for (j = 0; j < passes; ++j)
			for (i = 0; i < stringlen; string[i % stringlen] += key[i % keylen], ++i);

		if (i != -1)
			printf("The encrypted phrase is:\n%s", string);
	}
}
