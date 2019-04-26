/****************************
Filename: YesNoGame.c
Name: Blakely North
Date Last Edited: 9-21-2018
Brief Description: Starting point for a yes no game
gcc -Wall -Wextra -O -ansi -pedantic -o yesnogame YesNoGame.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>
int main(void)
{
	/*valid inputs will be y, n, and q to quit*/
	char input;
	/*-1 descibes the starter event*/
	int eventID = -1;
	/*change this if you want to add more events*/
	int maxEventID = 16;
	/*Add other game variables here, this could include a currency, special event triggers, how far down a specific event chain they are, ect.*/


	/*EXAMPLE extra variable*/
	int cleancut = 0;
	/*set random seed*/
	/*srand(time(NULL));*/
	/*Add the introduction to the game here, explain the rules to user */



	do
	{
		/*setting input to 'a' resets the input*/
		input = 'a';
		/*switch on the event, in each have something desribe what the options are (y/n)*/
		switch(eventID)
		{
			case -1:
				printf("You wake up on a beach. The last thing you remember is a plane crash.\n You stand up. Suddenly, you feel a sharp pain and notice a gash in your left leg. (Press 1 to continue) \n");
				break;
			case 0:
				printf("You see a beach and the ocean on your left and a pool of water on your right. Do you want to go to the fresh water (1) or the salt water (2)?\n");
				break;
			case 1:
				printf("You gaze into the water. It looks clear. Do you want to wash your cut out? (1 is yes, 2 is no)\n");
				break;
			case 2:
				printf("You gaze into the water. It looks clear. Do you want to wash your cut out? (1 is yes, 2 is no)\n");
				break;
			case 3:
				printf("Oh no! There was a parasite in the water and now you have an infection.\nYou see a forest and a mountain. Do you want to go to the forest and try to find food (1), or climb the mountain and try to see the whole island  (2)?\n");
				break;
			case 4:
				printf("You decide not to wash your cut out.\nYou look around and you see a river that leads into the pool of water and a mountain. Do you want to follow the river and try to find its source  1), or climb the mountain and try to see the whole island (2)?\n");
				break;
			case 5:
				printf("You wash your cut out. Now, your cut is clean, and it has magically stopped bleeding.\nYou see a forest and a mountain. Do you want to go to the forest and try to find food (1), or climb the mountain and try to see the whole island (2)?\n");
				break;
			case 6:
				printf("You decide not to wash your cut out.\nYou see a forest and a mountain. Do you want to go to the forest and try to find food (1), or climb the mountain and try to see the whole island (2)?\n");
				break;
			/*FOREST*/
			case 7:
				printf("While in the forest, you see a tree with a hole in it. You can also see a small, shiny object shimmering in the sunlight. Do you want to investigate the hole (1), or the shiny object (2)?\n");
				break;
			case 8:
				printf("You make your way to the base of the mountain.\nWhile at the base of the mountain, you see a black fuzzy object. It stands up! It's a bear! Do you want to make friends with it (1) or run from it (2)?\n");
				break;
			case 9:
				printf("While walking up the side of the river, you see a log that crosses into the forest on the other side. you also see that the river leads to the mountain. Do you want to go across the log into the forest (1), or keep following the river to the mountain (2)?\n");
				break;
			case 10:
				printf("The bear says to you  \"Hi, My name is Karl. I've been stuck on this island for two years now, and I am looking for a friend. Do you want to be my friend?\" (1=Yes, 2=No).\n");
				break;
			case 11:
				printf("You make your way up the river.\nEventually, you reach the base of the mountain, you see a black fuzzy object. It stands up! It's a bear! Do you want to make friends with it (1) or run from it (2)?\n");
				break;
			case 12:
				printf("You turn and run away, up the mountain. The bear catches up to you and before killing you, you hear him say \"ALL I WANTED WAS TO BE FRIENDS! WHY ARE YOU HUMANS SO MEAN?!\"\n");
				break;
			case 13:
				printf("You and Karl the bear live happily ever after.\n");
				break;
			case 14:
				printf("You walk towards the shiny object. you bend down to pick it up, but as you touch it, a vicious bird swoops down and lifts you high into the clouds and you were never seen again.\n");
				break;
			case 15:
				if (cleancut == 0)
				{
					printf("You walk towards the tree and begin to climb. But as you reach the top. your cut leg slips, and you fall. As you hit the ground, you hear a pop. Your leg has snapped.\n");
					break;
				}
				else if (cleancut == 1)
				{
					printf("You walk up to the tree and start to climb. as you reach the hole, you see a light coming from the inside.\nYou keep going. Suddenly, you feel a strong force pulling you towards the hole, almost like gravity.\nYou are sucked into a portal inside the tree and you are spat out in Uganda.\n\nYou win!");
					break;
				case 16:
					printf("Press 1 or 2 to restart.\n");
					break;
				}
		}


		/*accept a character as input q quits everyting else should be n or y if none keep checking*/
		while(input != '1' && input != '2'&& input != 'q')
		{
			printf("\nEnter '1' for option one or '2' for option two ('q' to quit):\n");
			/*scanf goes here*/
			scanf(" %c", &input);

		}
		/*switch on the event change outcome based on input*/
		switch(eventID)
		{
			case -1:
				if(input == '1')
				{
					printf("\n");
					eventID = 0;
				}
				else if(input == '2')
				{
					printf("Rebel! I told you to press 1!\n");
					eventID = 0;
				}
				break;
			case 0:
				/*Add what happens in each answer down here, they can adjust variables*/
				if(input == '1')
				{
					printf("\n");
					eventID = 2;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 1;
				}
				break;
			case 1:
				if(input == '1')
				{
					printf("\n");
					cleancut = 1;
					eventID = 5;
				}
				else if(input == '2')
				{
					printf("\n");
					cleancut = 0;
					eventID = 6;
				}
				break;

			case 2:
				cleancut = 0;
				if(input == '1')
				{
					printf("\n");
					eventID = 3;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 4;
				}
				break;

			case 3:
				if(input == '1')
				{
					printf("\n");
					eventID = 7;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 8;
				}
				break;

			case 4:
				if(input == '1')
				{
					printf("\n");
					eventID = 8;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 9;
				}
				break;

			case 5:
				if(input == '1')
				{
					printf("\n");
					eventID = 7;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 8;
				}
				break;

			case 6:
				if(input == '1')
				{
					printf("\n");
					eventID = 7;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 8;
				}
				break;

			case 7:
				if(input == '1')
				{
					if(cleancut == 1)
					{
						printf("\n");
						eventID = 15;
					}
					else if(cleancut == 0)
					{
						printf("\n");
						eventID = 16;
					}
					break;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 14;
				}
				break;

			case 8:
				if(input == '1')
				{
					printf("\n");
					eventID = 10;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 12;
				}
				break;

			case 9:
				if(input == '1')
				{
					printf("\n");
					eventID = 7;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 11;
				}
				break;

			case 10:
				if(input == '1')
				{
					printf("\n");
					eventID = 13;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 12;
				}
				break;

			case 11:
				if(input == '1')
				{
					printf("\n");
					eventID = 10;
				}
				else if(input == '2')
				{
					printf("\n");
					eventID = 12;
				}
				break;

			case 12:
			input = 'q';

				{
					printf("\nYou lose.");
					eventID = 16;
				}
				break;

			case 13:
				input = 'q';
				{
					printf("\nYou win!");
					eventID = 16;
				}
				break;

			case 14:
			input = 'q';
				{
					printf("\nYou lose.");
					eventID = 16;
				}
				break;

			case 15:
			eventID = 16;


				break;
			case 16:
				if(input == '1')
					{
						eventID = -1;
					}
				else if(input == '2')
					{
						eventID = -1;
					}
					break;
		}

		/*reset event id with rand*/
		/* eventID = rand() % (maxEventID + 1); */
		if(input != 'q')
		{
			getchar();
			getchar();
		}

	}while(input != 'q' || eventID != maxEventID) ;


	return 0;
}
