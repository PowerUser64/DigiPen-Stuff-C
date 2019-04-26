/****************************
Filename: 6.5-PyramidGenerator.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a 6-PyramidGenerator.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
	char exit = 'n';
	do
	{
		int starsToPut = -1, spacesToPut = -1, j, i, input, height;
		printf("How tall should the pyramid be?\n(Enter the number 13579 to quit)\n");
		scanf("%i", &input);
		height = input;
		spacesToPut = height - 1;
		if (input != 13579)
		{
			for (starsToPut = 1, i = 0, j = 0; i < input; i++, height--)
			{
				for (j = 0; j < spacesToPut; j++)
					putchar(' ');

				for (j = 0; j < starsToPut; j++)
					putchar('*');

				starsToPut += 2;
				spacesToPut--;
				putchar('\n');
			}
		}
		if (input == 13579)
			exit = 'y';
	} while (exit != 'y');
	return 0;
}