/****************************
Filename: 5-AnyDigit_NumberReverse.c
Name: Blakely North
Date Last Edited: 12-11
Brief Description: Reverses any int you put in to it
gcc -Wall -Wextra -O -ansi -pedantic -o 5-AnyDigit_NumberReverse 5-AnyDigit_NumberReverse.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
    int input, reversedNumber = 0, remainder;
    /* Wait for user input */
    printf("Enter an integer: ");
    scanf("%i", &input);

    /* Basically eats away at the user's input by moving the decimal point (because it is an int), then slowly adds it to the output variable.*/
    while (input != 0)
    {
        remainder = input % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        input /= 10;
    }
    /* Final output */
    printf("Reversed Number = %d", reversedNumber);

    return 0;
}
