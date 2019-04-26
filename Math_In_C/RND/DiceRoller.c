/****************************
Filename: DiceRoller.c
Name: Blakely North
Date Last Edited: 9-25-2018
Brief Description: Roll any type and amount of die
gcc -Wall -Wextra -O -ansi -pedantic -o Roll DiceRoller.c
****************************/


/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/* function prototypes*/
int diceroller(int numofdice, int dietype);

int  main(void)
{
  int numofdice, dietype;
  /* setrive dice values from user of what to roll. uses a spesfic format - # D #*/
  srand(time (NULL));
    /*shuffle fast*/
  rand();
  printf("Type the number of dice then the number of faces on the die\n");
  printf("use the format #d#\n");
  scanf(" %i d %i", &numofdice, &dietype);

  printf("total roll: %i\n", diceroller(numofdice, dietype));
  return 0;
}

int diceroller( int numofdice, int dietype)
{
    int i, total = 0;
    for(i = 0 ; i< numofdice ; ++i)
    {
      int dieroll;
      /* simulates one die roll*/
      dieroll=(rand() %dietype) +1;
      printf("Die #%i rolled a %i\n", i+1, dieroll );
      total += dieroll;
    }
  return total;
}
