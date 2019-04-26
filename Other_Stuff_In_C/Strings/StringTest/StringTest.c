/******************************
 * Filename: StringTest.c
 * Name: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: A sample and standard new file
   gcc -Wall -Wextra -O -ansi -pedantic -o StringTest StringTest.c
 ******************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
  int i, j;
  char string1[] = {'P', 'i', 'k', 'a', 'c', 'h', 'u'};
  char *strptr = "Typhlosion";
  char string2[] = "Koffing";

  puts(string1);
  puts(strptr);
  puts(string2);
  /*
  bad cuz were overwritind string literal
  strcpy(strptr, string1);
  not enough space
  strcpy(string1, strptr);
  */
  strcpy(string2, strptr);

  puts(string2);
  printf("Is %s before, after, or equal to %s lexiographically?", string1, strptr);
  i = strcmp(string1, strptr);
  if(i == 0)
    puts("They are equal");
  else if(i < 0)
    puts("the first is first");
  else if(i > 0)
    puts("the latter is first");

  return 0;
}
