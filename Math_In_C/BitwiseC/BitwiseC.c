/****************************
Filename: BitwiseC.c
Name:Blakely North
Date Last Edited:9-19-2018
Brief Description: Starting point for a yes no game
gcc -Wall -Wextra -O -ansi -pedantic -o BitwiseC BitwiseC.c
****************************/
#include <stdio.h>

int main(void)
{
  char a = 0;  /*00000000*/
  char b = 127; /*01111111*/
  char c = 55; /*00110111*/
  printf("a is %x, b is %x, and c is %x\n",a,b,c);
  printf("a & b is %x, b & c is %x, and c & a is %x\n",a & b,b & c,c & a);
  printf("a or b is %x, b or c is %x, and c or a is %x\n",a | b,b | c,c | a);

return 0;
}
