/******************************
 * Filename: MemoryLeaker.c
 * Author: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: A sample and standard new file
   gcc -Wall -Wextra -O -ansi -pedantic -o MemoryLeaker MemoryLeaker.c
 ******************************/
/*printf, scanf*/
#include <stdio.h>
/*malloc*/
#include <stdlib.h>

int power(int base, int exp)
{
    int i;
    for (i = 0; i < exp; ++i)
        base *= base;
    return base;
}

int main(void)
{
    int input;
    int *h;
    char unit;
    puts("This program was created as a joke, hasn't been tested, and it can be used to do bad things, so I must issuea a disclaimer:");
    puts("WARNING:\nTHIS PROGRAM LEAKS MEMORY!\nTHIS MEANS THAT IT BASICLALLY EATS IT UNTILL YOU RESTART YOUR COMPUTER\n\nPLEASE ONLY RUN THIS IF YOU KNOW EXACTLY WHAT A MEMORY LEAK IS!!!\n\nPress Ctrl+C or close this window if you don't know what a memory leak is");
    ;
    puts("\nOkay, enough intro");
    puts("Enter how much memory then the units (b, k, m, or g) that you want to leak like so:\n53, b");
    scanf("%i, %c", input, unit);
    while (getchar() != '\n')
        ;
    switch (unit)
    {
    case 'b':
        input *= power(10, 0);
        break;
    case 'k':
        input *= power(10, 3);
        break;
    case 'm':
        input *= power(10, 6);
        break;
    case 'g':
        input *= power(10, 9);
        break;
        printf("Are you SURE you want to leak %i bytes of memory\n", input);
        if (getchar() != 'y')
            return -1;
        h = malloc(input);
        if (!h)
        {
            printf("Failed to get %i bytes of memory\n", input);
            while (getchar() != '\n')
                ;
            return -2;
        }
        printf("%i bytes of memory have been successfully claimed\n", input);
        printf("Are you 1000% sure you want to have %i bytes of memory to be GONE from your machine until you restart?\n(y/n):", input);
        if (getchar() == 'y')
            return 1;
        else
        {
            free(h);
            putchar('\n');
            puts("Operation canceled\nPress enter to exit");
            while (getchar() != '\n')
                ;
            return 0;
        }
        return -3;
    }
}