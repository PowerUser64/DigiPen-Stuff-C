/********************
FileName: tripleCube.c
Name: Blakely North
Date: 9-28-18
Brief Description: Calculates pi using variouus methods
gcc -Wall -Wextra -O -ansi -pedantic -o tripleCube.exe tripleCube.c main.c
*********************/
#include <stdio.h> /* printf */

	int i, j, k, ones, tens, hundreds, temp, cubesum;

void print_cubes(void)
{
	/* For each 3-digit number*/
	for( i = 100 ; i <= 999 ; i++)
	{
		temp = i;

		/*Extract and save the the first digit*/
		hundreds = temp / 100;

		/*Extract and save the second digit*/
		temp %= 100;
		tens = temp / 10;

		/*Extract and save the third digit*/
		temp %= 10;
		ones = temp;
		/*Cube first digit*/
		hundreds *= hundreds * hundreds;
		/*Cube second digit*/
		tens *= tens * tens;
		/*Cube third digit */
		ones *= ones * ones;
		/*Add up the cubes*/
		cubesum = ones + tens + hundreds;
		/*If the sum equals the number then*/
		if(cubesum == i)
		{
			/*Print the number*/
			printf("%i has the cube property. (%i + %i + %i)\n", i, hundreds, tens, ones);
		}
	}
}

void print_pythagorean_triples(int low, int high)
{
	int totalTriples = 0;
	/*these 3 loops go through every combination of numbers from low to high without repeating*/
	for(i = low; i < high; i++)
	{
		for(j = i; j < high; j++)
		{
			for(k = j; k < high ; k++)
			{
				/*judges if a pythgorean triple (aka fits a^2 + b^2 = c^2)*/
				if(i*i + j*j == k*k)
				{
					totalTriples++;
					printf("Triple #%3i: %3i,%3i,%3i --> %4i + %4i = %4i\n", totalTriples, i, j, k, i*i, j*j, k*k);
				}
			}
		}
	}
	return ;
}
