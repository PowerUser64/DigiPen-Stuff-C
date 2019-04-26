/****************************
Filename: ColorCalc.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o ColorCalc ColorCalc.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/*
Wave Length (in nm)	Color
< 380	invisible
380–450	violet
450–495	blue
495–570	green
570–590	yellow
590–620	orange
620–750	red
>750	invisible
*/

int main(void)
{
  int i;
  printf("What is the wavelength? ");
  scanf("%i", i);
  putchar('\n');
  if (i < 380)
    printf("Invisible");
  else if (i <= 450)
    printf("Violet\n");
  else if (i <= 495)
    printf("Blue\n");
  else if (i <= 570)
    printf("Green\n");
  else if (i <= 590)
    printf("Yellow\n");
  else if (i <= 620)
    printf("Orange\n");
  else if (i <= 750)
    printf("Red\n");
  else if (i > 750)
    printf("Invisible\n");
  return 0;
}
