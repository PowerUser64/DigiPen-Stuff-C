/****************************
Filename: YesNoGame.c
Name:
Date Last Edited:
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
	int maxEventID = 2;
	/*Add other game variables here, this could include a currency, special event triggers, how far down a specific event chain they are, ect.*/
	
	
	/*EXAMPLE extra variable*/
	int event1Seq = 0;
	/*set random seed*/
	srand(time(NULL));
	/*Add the introduction to the game here, explain the rules to user */
	
	
	
	do
	{
		/*setting input to 'a' resets the input*/
		input = 'a';
		/*switch on the event, in each have something desribe what the options are (y/n)*/
		switch(eventID)
		{
			case -1:
				printf("Welcome here you get to make choices about your kingdom!\n");
				break;
			case 0:
				/*Add what each case is asking here in each case*/
				break;
			case 1:
				/*example with a event sequence*/
				if(event1Seq == 0)
				{
					printf("Do we have enough coconuts?\n");
				}
				else if(event1Seq == 1)
				{
					printf("We have too many coconuts. Throw them to the townspeople?\n");
				}
				break;
			case 2:
				
				break;
		}
		
		
		/*accept a character as input q quits everyting else should be n or y if none keep checking*/
		while(input != 'n' && input != 'y'&& input != 'q')
		{
			printf("\nEnter 'y' for yes or 'n' for no ('q' to quit):\n");
			/*scanf goes here*/
			scanf(" %c", &input);
			
		}
		/*switch on the event change outcome based on input*/
		switch(eventID)
		{
			case -1:
				if(input == 'y')
				{
					printf("With any luck we wil prosper!\n");
				}
				else if(input == 'n')
				{
					printf("This isn'e looking good...\n");
				}
				break;
			case 0:
				/*Add what happens in each answer down here, they can adjust variables*/
				if(input == 'y')
				{
					
				}
				else if(input == 'n')
				{
					
				}
				break;
			case 1:
				/*Example with an event sequence*/
				switch(event1Seq){
					case 0:
						if(input == 'y')
						{
							printf("Very Wise.\n");
						}
						else if(input == 'n')
						{
							printf("Bring in more coconuts!\n");
							++event1Seq;
						}
						break;
					case 1:
						if(input == 'y')
						{
							printf("The townspeople don't like this and are revolting!");
							--event1Seq;
						}
						else if(input == 'n')
						{
							printf("Where did we even find all these coconuts, we aren't near a tropical climate...");
						}
						break;
				}
				break;
			case 2:
				if(input == 'y')
				{
					
				}
				else if(input == 'n')
				{
					
				}
				break;
		}
		
		/*reset event id with rand*/
		eventID = rand() % (maxEventID + 1);
		getchar();
		getchar();
		
	}while(input != 'q');
	
	
	return 0;
}

