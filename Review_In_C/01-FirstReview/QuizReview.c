/****************************
Filename: QuizReview.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o QuizReview QuizReview.c
****************************/
/* includes are at the top of the file */

/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>
/* function prototypes here, basicly tells compiler how to use the function before it is defined*/
void countdown( int i );

int main(void)
{
  /* Vars need to be named with alphanumaric chars and _'s, but cant start with a keyword or inderscore.*/
  int i = 10;
  /* runs if the value in the () is true*/
  if(i>10)
  {
    printf("is less than 2\n");
  }
  /* runs if the first if statement was false*/
  else if(i<10)
  {
    printf("i is less than 10\n");
  }
  /* runs if all other if's and elseif's are false*/
  else
  {
    printf("i is equal to 10 \n");
  }
  /* switches require an integral value and will jump to the case that corresponds to the integral*/
  switch (i)
  {
    /* this is the general way to make a case, breakes once completed.*/
    case 1:
      printf("Number is smoll\n");
      break;
      /* if the case has no break, it keeps going to the next case (or past the end).*/
    case 10:
      printf("Roses are red.\n");
    case 20:
      printf("So are books.\n");
      break;
    /* cases don't need to be in order*/
    case 2:
      printf("Why is this here?\n");
      break;
    case 12:
    case 13:
      printf("Both numbers print this\n");
    /* default case is used if i isn't any of the other case #'s'*/
    default:
      printf("Error: not cool.\n");
      break;
  }
  /* break statments jump here*/
  /* while loops run 0<= tomes based on a true/false value*/
  while(i>=0)
  {
    /* post decrement means it lowers the value after the line is finished */
    printf("countdown: %i\n", i--);
  }
  /* the same loop but with do while do while runs 1<= times*/
  do {
    printf("Do Countdown: %i\n", i--);
  } while(i>=0);
  /* for loop version.*/
  /* 1st statement is run*/
  /* 2nd statement is checked at start*/
  /* 3rd statementruns after the body of the loop each time*/
  for ( i = 10; i >= 0 ; --i)
  {
    printf("For countdown: %i\n", i);
  }
  i = 10;
  printf("I is %i before the function\n", i);
  countdown(i);
  printf("i is %i after the function\n", i);
  return 0;
}


/* count is recursive (it calls its' self)*/
void countdown(int i)
{
    printf("Function countdown: %i\n", i);
    if (i>= 0)
      countdown(i-1);
}
