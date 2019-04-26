/**********************
ZombieDice.c
By: Ryan Scheppler and finished by :
Last Edited: 9/27/17
Brief: A dice game meant for up to 8 people, player with the most after one gets 13 or more brains wins
gcc -Wall -Wextra -ansi -pedantic -O -o ZombieDice ZombieDice.c
**********************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

#define GREEN 0

#define YELLOW 1

#define RED 2

#define MAXPLAYERS 8
/*declare functions*/
/*A full player's turn returns how many brains they earned*/
int PlayerTurn();
/*shuffle all brains back into bag not the shots return total dice*/
int RefreshDice(int dicePool[], int shotArray[], int current3Dice[]);
/*Call to pause for an enter*/
void WaitForEnter();

int main(void)
{
	int NumOPlayers = -1;
	int playerScores[MAXPLAYERS] = {0};
	int currentPlayer = 0;
	int i, winner;
	
	srand(time(NULL));
	
	while (NumOPlayers <= 0 || NumOPlayers > MAXPLAYERS)
	{
		printf("Input Number of Players!: ");
		scanf(" %i", &NumOPlayers);
		WaitForEnter();
	}
	/*game loop, will break when and condition is met*/
	while(1)
	{
		/*end condition*/
		if(playerScores[currentPlayer] >= 13)
		{
			break;
		}
		
		
		WaitForEnter();
		
		
		
		
	}
	/*TODO: figure out who won here in a loop also print scores*/
	
	
	
	return 0;
}
/*A full player's turn returns how many brains they earned*/
int PlayerTurn()
{
	/*turn set up*/
	/* dice cup/bag */
	int dicePool[3] = {0};
	/* if you geta  shot, record each color as you do */
	int shotArray[3] = {-1, -1, -1};
	/* these are the 3 currently in your hand */
	int current3Dice[3] = {-1, -1, -1};
	char input = 'y';
	/* number of brains this turn */
	int brains = 0;
	/* number of shots so far this turn */
	int shots = 0;
	int diceRemaining;
	/* set arrays for start of turn */
	diceRemaining = RefreshDice(dicePool, shotArray, current3Dice);
	
	
		
		
		
	
	return brains;
	
}
/*shuffle all brains back into bag not the shots return total dice, use to set up and when the player needs to shuffle beyond original 13 dice*/
int RefreshDice(int dicePool[], int shotArray[], int current3Dice[])
{
	
	int i, total;
	/*green dice total*/
	dicePool[GREEN] = 6;
	/*yellow dice total*/
	dicePool[YELLOW] = 4;
	/*red dice total*/
	dicePool[RED] = 3;
	/*all dice*/
	total = dicePool[GREEN] + dicePool[YELLOW] + dicePool[RED];
	printf("Refreshing Dice Pool\n");
	/*remove dice currently saved as a shot*/
	for(i = 0; i <3 ; i++)
	{
		if(shotArray[i] > -1)
		{
			dicePool[shotArray[i]] -= 1;
			total--;
		}
		if(current3Dice[i] > -1)
		{
			dicePool[current3Dice[i]] -= 1;
			total--;
		}
	}
	return total;
}
/*Call to pause for an enter, also needs to be used after scanf if used to remove any excess characters and newlines*/
void WaitForEnter()
{
	char input = 'a';
	while(input != '\n')
	{
		input = getchar();
	}
}