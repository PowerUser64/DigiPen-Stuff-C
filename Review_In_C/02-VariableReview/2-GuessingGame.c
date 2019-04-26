/****************************
Filename: 2-GuessingGame.c
Name: Blakely North
Date Last Edited: 12-11
Brief Description:A simple guessing game. The computer picks a num, and the user guesses it.
gcc -Wall -Wextra -O -ansi -pedantic -o 2-GuessingGame 2-GuessingGame.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/* generate a random number */
int randomnum(int low, int high)
{
	int RNDNum;
	RNDNum = rand() % ((high + 1) - low) + low;
	return RNDNum;
}

int main(void)
{
	/* low and high values*/
	int low = 0, high;
	/* rnd output*/
	int RNDNum;
	/* user input*/
	int input;

	printf("What is the highest value that you want to guess to?\n");
	scanf("%i", &high);
	srand(time(NULL));
	RNDNum = randomnum(low, high);
	do
	{
		input = NULL;
		printf("Input your guess:");
		scanf("%i", &input);
		printf("\n");
		if (input > RNDNum)
			printf("Lower.\n");

		else if (input < RNDNum)
			printf("Higher\n");
	} while (input != RNDNum);
	printf("Correct!\n");
	return 0;
}