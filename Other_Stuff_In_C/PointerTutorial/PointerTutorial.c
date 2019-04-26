/****************************
Filename: PointerTutorial.c
Name: Blakely North
Date Last Edited:11-02-2018
Brief Description: This shows how to use pointers
gcc -Wall -Wextra -O -ansi -pedantic -o PointerTutorial PointerTutorial.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

void byValue(int i)
{
  i = 99;
  printf("in byValue, i is %i\n", i);
}
void byRefrence(int* i)
{
  *i = 6084;
  printf("In byRefrence, i is %i\n", *i);
}
int main(void)
{
  int i, j;
  /*when making a pointer, you tell it what type it points to followed by the variable name, the & (address) poerater retrieves the mem address of the var it effects*/
  int* pi = &i; /*
  pi = &7;
  this doesn't work, you can't get the address of a constent */
  /* You cn make a pointer point to a pointer, essentially having a star for each level of pointer */
  int** ppi = &pi;
  int a[] = {0,1,2,3,4};
  /* a[2] is the same thing as *(a+2) and a+2 and &(a+2) */
  /* Derefrence (*) pi is set to 3*/
  *pi = 3;
  printf("i is now %i\n", i);
  /*Derefrence ppi twice can also edit i*/
  **ppi = 42
  ;printf("i is now %i\n", i);
  /* you can't do the following, showing you cant address a constent
  ppi = &&i;
  */
  /* we can set the pointer pi to the point at the array a */
  pi = a;
  /* loop ang print out an array using a pointer and pointer arithmetic*/
  for (j = 0; j < 5; j++)
  {
    printf("a[%i] is set to %i\n", j, *(pi++) );
  }
  byValue(i);
  printf("Outside byValue, i is %i\n", i);
  byRefrence(&i);
  printf("Outside byRefrence, i is %i\n", i);
  return 0;
}
