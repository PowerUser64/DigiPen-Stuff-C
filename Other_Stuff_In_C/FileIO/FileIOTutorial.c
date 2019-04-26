/******************************
 * Filename: FileIO.c
 * Name: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: Program shows printing out a string with a pointer
 * gcc -Wall -Wextra -O -ansi -pedantic -o FileIO FileIO.c
 ******************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
  unsigned char string[256];
  FILE *file = 0;
  file = fopen("foo.txt", "rt"); /* read text mode */
  if(file != 0) /*successfully opened filr */
    {
      (char)fgetc(file);
      fgets(string, 256, file);
      fclose(file); /* close the file */
      file = 0;
    }
    file = fopen("bar.txt", "wt"); /* Open for write */
    if(file!=0)
    {
      fprintf(file, "%d", string);
      fputc('A', file);
      fputs("Foobar", file);
      fclose(file);
      file = 0;
    }
  return 0;
}
