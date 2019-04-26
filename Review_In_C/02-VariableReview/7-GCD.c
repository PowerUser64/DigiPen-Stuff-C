/****************************
Filename: GCD.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a 7-GCD.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/******************************
Actions to be Performed
=======================

1----------
Assign the larger number to M, and the smaller number to N.

2-----------
Divide M by N (M/N) and assign the remainder to R.

3-----------
If R is not 0, then assign the value of N to M, assign the value of R to N, and return to step 1.
If R = 0, then the GCD is N and the algorithm terminates.

*****************************************/

int main(void)
{
	int M, N, R, i;
	printf("Enter two numbers with a space between them.\n");
	scanf("%i %i", &M, &N);
	do
	{
		/* Assign the larger number to M, and the smaller number to N. */
		if (M < N)
			i = M, M = N, N = i, i = 0;
		/* Divide M by N (M/N) and assign the remainder to R. */
		R = M % N;
		/*If R is not 0, then assign the value of N to M, assign the value of R to N, and return to  step 2*/
		if (R != 0)
			M = N, N = R;
		/* If R = 0, then the GCD is N and the algorithm terminates.*/
		else
			printf("The GCD is %i", N);
	} while (R != 0);
	return 0;
}

/***************************************************
 * OTHER METHOD
{
    int n1, n2, i, gcd;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    for(i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }

    printf("G.C.D of %d and %d is %d", n1, n2, gcd);

    return 0;
}
***************************************************/