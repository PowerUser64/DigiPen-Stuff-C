/****************************
Filename: RAMEditor.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o RAMEditor RAMEditor.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/* generate a random number */
int randomnum(int low, int high)
{
  int RNDNum;
  RNDNum = rand() % ((high + 1) - low) + low;
  return RNDNum;
}

int main(void)
{
  int address, i;
  printf("What do you want to do? Press 1 for one address, press 2 if you want to edit a block or a range of addresses.");
  scanf("%i", i);
  /* One adderess */
  if (i = 1) 
  {
    
  }
  
  return 0;
}
