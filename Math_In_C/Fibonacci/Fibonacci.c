/****************************
Filename: YesNoGame.c
Name: Blakely North
Date Last Edited: 9-21-2018
Brief Description: Prints the Fibonacci sequence
gcc -Wall -Wextra -O -ansi -pedantic -o Fibonacci Fibonacci.c
****************************/
/*printf, scanf*/
#include <stdio.h>

int main(void)
{
  /* set up variables*/

  int fn, n = 3, maxN, fn1 = 1, fn2 = 0;
  /*Accept input on how many numbers to print*/
  printf("Which term do you want to calculate to?\n");
  scanf("%i\n", &maxN );

  /* print first two terms*/
  printf("%i,", fn2 );
  printf("%i,", fn1 );

  /*loop untill we go above the user's input value.*/
  while(n <= maxN)
  {
    fn = fn1 + fn2;
    /*calculate Fn and print it out*/
    printf("%i,", fn );
    /* set next loop's values*/
    fn2 = fn1, fn1 = fn, n++;
  }
  return 0;
}
