/*
Formatted IO.c
By: Blakely North
Last edited: 9/13/2018
Description: this file shows how tohandle standard i/o from the console
gcc -O -Wall -Wextra -ansi -pedantic -o Formatted_IO Formatted_IO.c
*/

/* printf scanf */
#include <stdio.h>

int main(void)
{
	int NumberOfSteamGames = 30;
	char MostPlayed[128] = "Portal 2";
	int HoursPlayed = 345;
	double MaxPrice = 20;
	
	/* Accept input from the console, rember to ask for what to input */
	printf("How many steam games do you own?\n");
	scanf(" %i", &NumberOfSteamGames);
	printf("What game do you play the most?\n");
	scanf(" %s", MostPlayed);
	printf("How many hours have you played that game for?\n");
	scanf(" %d", &HoursPlayed);
	printf("How much are you willing to spend on a steam game?\n");
	scanf(" %lf", &MaxPrice);
	
	/* Remember all you want to print can all go in a single line oe be spread out to be easier to read in the progrfilelength */
	
	printf("You have %i Steam games!\n", NumberOfSteamGames);
	printf("You play %s the most, and currently have %i hours.\n", MostPlayed, HoursPlayed);
	printf("You also prefer game prices to be under %.2f\n", MaxPrice);
	return 0;
}