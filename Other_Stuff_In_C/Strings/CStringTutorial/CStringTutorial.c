/******************************
 * Filename: CStringTutorial.c
 * Name: Blakely North
 * Date Last Edited:
 * Brief Description:
   gcc -Wall -Wextra -O -ansi -pedantic -o CStringTutorial CStringTutorial.c
 ******************************/
#include <stdio.h>

/* this function takes a string and counts the chars until a null char.*/
int strlength(const char *string);
/* this function accepts 2 strs as paramaters, one as a src and will overwrite the src to the destination, ensuring that the destination has space. returns a pointer to the new str. */
char *strcpy(const char *src, char *dest);
/* this one ensures that dest has enough space to fit src.*/
char *strcat(const char *src, char *dest);
int main(void)
{
  char str1[256] = "Hello, my name is Inigo Montoya. ";
  char str2[256] = "You killed my father, prepare to die!";
  puts(str1), puts(str2);
  printf("\nLength of str1 is: %i\n", strlength(str1));
  printf("\nLength of str2 is: %i\n", strlength(str2));

  puts("Concatenating strings");
  puts(strcat(str2, str1));
  puts("Coppying strings");
  puts(strcpy(str1, str2));

  return 0;
}

/* this function takes a string and counts the chars until a null char.*/
int strlength(const char *str)
{
  int length;
  for (length = 0; str[length] != '\0'; ++length)
    putchar(str[length]);
  return length;
}
/* this function accepts 2 strs as paramaters, one as a src and will overwrite the src to the destination, ensuring that the destination has space. returns a pointer to the new str. */
char *strcpy(const char *src, char *dest)
{
  const char *s = src;
  char *d = dest;
  while (*s != '\0')
  {
    *d = *s;
    ++d;
    ++s;
  }
  *d = '\0';
  return dest;
}
/* this one ensures that dest has enough space to fit src.*/
char *strcat(const char *src, char *dest)
{
  char *d = dest;
  while (*d != '\0')
    d++;
  while (*src != '\0')
  {
    *d = *src;
    d++;
    src++;
  }
  *d = '\n';
  return dest;
}