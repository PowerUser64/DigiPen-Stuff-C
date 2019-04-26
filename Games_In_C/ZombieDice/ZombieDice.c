/**********************
ZombieDice.c
By: Ryan Scheppler and finished by :Blakely North
Last Edited: 9/31/18
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

int randomnum(int low, int high);

int main(void)
{
	int NumOPlayers = -1;
	
	int playerScores[MAXPLAYERS] = {0};
	int currentPlayer = 0;
	int i, winner;

	srand(time(NULL));

	while (NumOPlayers <= 0 || NumOPlayers > MAXPLAYERS)
	{
		printf("Input Number of Players: ");
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

		printf("It's player %i's turn.\nPress enter.\n", currentPlayer + 1);

		WaitForEnter();

		/* TODO: adjust the current players score, in the array playerScores, by adding the PlayerTurn function to it */
		playerScores[currentPlayer] += PlayerTurn();
		/* TODO: move to next player if at last player move to first player*/
		currentPlayer++;
		if (currentPlayer >= NumOPlayers)
		{
			currentPlayer = 0;
		}
		/* TODO: Print out current scores in some way, should use a loop, but if you want to make a function for it can */
		for (i = 0; i < NumOPlayers; i++)
		{
			printf("Player %i's score is %i.\n", i + 1, playerScores[i]);
		}
	}
	/*TODO: figure out who won here in a loop also print scores*/
	printf("Final scores:\n");
	for (i = 0; i < NumOPlayers; i++)
	{
		printf("Player %i's score is %i.\n", i + 1, playerScores[i]);
	}

	printf("The winner is...\n");

	for (i = 0, winner = 1; i < NumOPlayers; i++)
	{
		if (playerScores[winner] < playerScores[i])
		{
			winner = i;
		}

	}
	printf("Player %i!\n", i);
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
	int RNDNum, i;
	/* set arrays for start of turn */
	diceRemaining = RefreshDice(dicePool, shotArray, current3Dice);

	/* TODO: loop through each roll while input is 'y' */
	do {

		/* TODO: if not enough dice remaining (3), refresh dice pool */
		if (diceRemaining < 3)
		{
			diceRemaining = RefreshDice(dicePool, shotArray, current3Dice);
		}
		/* TODO: Roll 3 dice and figure out the results , loop through the 3 dice (colors) in current3Dice*/
		for(i = 0 ; i < 3 ; i++ )
		{
			/*printf("i si currently %i\n", i);*/
			/* TODO: if current3Dice at the current index is -1 select a die from the dicePool array */
			if(current3Dice[i] == -1)
			{
				/* TODO: when selecting choose randomly based on the number of diceRemaining (don't forget to remove from pool and diceRemaining number)*/

				RNDNum = randomnum(0, diceRemaining-1);
				if(RNDNum < dicePool[GREEN])
				{
					dicePool[GREEN]--;
					current3Dice[i]= GREEN;
					/*printf("      this is a green die\n");*/
				}

				else if(RNDNum < dicePool[YELLOW] + dicePool[GREEN])
				{
					dicePool[YELLOW]--;
					current3Dice[i] = YELLOW;
					/*printf("      this is a yellow die\n");*/
				}

				else if(RNDNum < dicePool[RED] + dicePool[YELLOW] + dicePool[GREEN])
				{
					dicePool[RED]--;
					current3Dice[i] = RED;
					/*printf("      this is a red die\n");*/
				}
				diceRemaining--;
			}

			/* TODO: Roll current dice with 6 possible sides */
			RNDNum = randomnum(0, 5);
			/* TODO: switch based on what color die you rolled to figure out results (print die type and what gets rolled) */
			switch (current3Dice[i])
			{
				case GREEN:
				if(RNDNum >= 3)
				{
					brains++;
					current3Dice[i] = -1;
					printf("It's a green brain!\n");
				}

				else if(RNDNum >= 1)
				{
					printf("It's a green runner!\n");
				}

				else if(RNDNum == 0)
				{
					if(shots < 3)
						shotArray[shots] = GREEN;
					shots++;
					current3Dice[i] = -1;
					printf("Oh no! A green shot!\n");
				}
				break;

				case YELLOW:
				if(RNDNum >= 4)
				{
					printf("It's a yellow brain!\n");
					current3Dice[i] = -1;
					brains++;
				}

				else if(RNDNum >= 2)
				{
					printf("It's a yellow runner!\n");
				}

				else if(RNDNum >= 0)
				{
					if(shots < 3)
						shotArray[shots] = YELLOW;
					shots++;
					current3Dice[i] = -1;
					printf("Oh no! A yellow shot!\n");
				}
				break;

				case RED:
				if(RNDNum >= 3)
				{
					if(shots < 3)
						shotArray[shots] = RED;
					shots++;
					current3Dice[i] = -1;
					printf("Oh no! A red shot!\n");
				}

				else if(RNDNum >= 1)
				{
					printf("It's a red runner!\n");
				}

				else if(RNDNum == 0)
				{
					brains++;
					current3Dice[i] = -1;
					printf("It's a red brain!\n");
				}
				break;

			}
		}
		printf("Press enter\n");
		WaitForEnter();

		/* TODO: if 3 shots return 0 */

		if (shots > 2)
		{
			return 0;
		}
		printf("Current score:\nBrains:%i\nShots:%i\n", brains, shots);
		input = 'a';

		/* TODO: check for input using scanf (use WaitForEnter() to clear enter from scanf), loop until they answer 'y' or 'n', make sure player is informed about the descision with printf */
		while(input != 'y' && input != 'n')
		{
			printf("Do you want to roll again?\n");
			scanf( "%c", &input);
			WaitForEnter();
		}

	} while(input == 'y');
	return brains;
}
/* generate a random number */
int randomnum(int low, int high)
{
  int RNDNum;
  RNDNum = rand() % ((high + 1) - low) + low;
  return RNDNum;
}

/*shuffle all brains back into bag not the shots return total dice, use to set up and when the player needs to shuffle beyond original 13 dice*/
int RefreshDice(int dicePool[], int shotArray[], int current3Dice[])
{

	int i, total;
	/*green dice total*/
	/*green dice total*/
	dicePool[GREEN] = 6;
	/*yellow dice total*/
	dicePool[YELLOW] = 4;
	/*red dice total*/
	dicePool[RED] = 3;
	/*all dice*/
	total = dicePool[GREEN] + dicePool[YELLOW] + dicePool[RED];
	/* printf("Refreshing Dice Pool\n"); */
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
