/****************************
Filename: NewFile.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o NewFile NewFile.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
  int i, x;
  for (i = 8, x = 10; x > i; i++){
    x -= i;}
  printf('% d, % d', i, x);

  return 0;
}
