/****************************
Filename: RandomNumGenerator.c
Name: Blakely North
Date Last Edited: 12-16-2018
Brief Description: A simple random number generator.
gcc -Wall -Wextra -O -ansi -pedantic -o RandomNumGenerator RandomNumGenerator.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/* generate a random number */
int randomnum(int low, int high);

int main(void)
{
    int low, high, RNDnum;
    do
    {
        srand(time(NULL));
        printf("Type the lowest and highest numbers to choose from with a space inbetween them. Type -100 and -100 to\n");
        scanf("%i %i", &low, &high);
        if (low != -100 && high != -100)
        {
            RNDnum = randomnum(low, high);
            putchar('\n');
            printf("Your random number is %i.", RNDnum);
            putchar('\n');
        }
        else
            RNDnum = -100;
    } while (RNDnum != -100);
    return 0;
}

/* generate a random number */
int randomnum(int low, int high)
{
    int RNDNum;
    RNDNum = rand() % ((high + 1) - low) + low;
    return RNDNum;
}