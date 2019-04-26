/****************************
Filename: Timer.c
Name: Blakely North
Date Last Edited:11-20-18
Brief Description: shows the timer function
gcc -Wall -Wextra -O -ansi -pedantic -o Timer Timer.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
  char input = 'a';
  /* print time while the user hits enter or q*/
  do {
    printf("Hit enter to see the time that has passed since 1-1-1970 in seconds.\nPress q to quit\n");
    /* Chechs input until a new line or q is reached.*/
    do {
      input = getchar();
    } while(input != 'q' && input != '\n');
    printf("The current time is %li\n", (long int)time(NULL));
  } while(input != 'q');
  return 0;
}
