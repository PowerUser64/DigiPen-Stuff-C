/****************************
Filename: 1-MileAndKilometerConverter.c
Name: Blakely North
Date Last Edited: 12-11
Brief Description: Converts between miles and kilometers
gcc -Wall -Wextra -O -ansi -pedantic -o 1-MileAndKilometerConverter 1-MileAndKilometerConverter.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
    /* i is for the og distance, j is for the result. */
    float i = 0, j = 0;
    int exit = 0;
    /* User input. Is ither M/m or K/k.*/
    char KmOrMi = 'k';
    /* If they want to quit */
    for(i = 0; exit == 0;)
    {
        /* User input */
        printf("What do you want to convert to?\nInput K for kilometers or M for miles. Press Q to quit.\n");
        KmOrMi = getchar();
        switch (KmOrMi)
        {
            /* If the user has miles and wants km */
        case 'k':
        case 'K':
            printf("How many miles?\n");
            scanf("%f", &i);
            j = i * 1.609344;
            printf("%f miles is %f kilometers\n", i, j);
            return 0;

            /* If the user has km and wants miles */
        case 'm':
        case 'M':
            printf("How many kilometers?\n");
            scanf("%f", &i);
            j = i * 0.621371;
            printf("%f kilometers is %f miles\n", i, j);
            break;

            /* If they quit */
        case 'q':
            exit = 1;
            break;
            /* Incase their response isn't valid */
        default:
            printf("Please input a valid response (K or M).\n");
            break;
        }
    }
    return 0;
}