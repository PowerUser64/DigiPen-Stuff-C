/*
Hello World.c
By: Blakely North
Last edited: 9/12/2018
Description: this file shows how to make a very simple program in C , and the expected style for files
gcc -O -Wall -Wextra -ansi -pedantic -o hello HelloWorld.c
*/
/* Includes are added here to allow the added use of functions not defined in this file */
#include <stdio.h>


/* Every C program needs exactly one function named main to start at */
int main(void)
{
	/* prints out a string */
	printf("Hello World!\n");
	return 0;
}