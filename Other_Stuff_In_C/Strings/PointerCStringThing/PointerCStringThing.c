/*************************************************************************************
 * Filename: PointerCSrtingThing.c                                                   *
 * Name: Blakely North                                                               *
 * Date Last Edited: 1-22-2019                                                       *
 * Brief Description: Program shows printing out a string with a pointer             *
 * gcc -Wall -Wextra -O -ansi -pedantic -o PointerCSrtingThing PointerCSrtingThing.c *
 *************************************************************************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
  /* array will be the size of the string on the right */
  char string[] = "Destiny 2 is an okay game\n";

  /* pointer can point at a char  in the array */
  char* sp;

  /* print out the array one char at a time */
  for(sp = string; *sp != '\0'; ++sp)
    putchar(*sp);

  return 0;
}
