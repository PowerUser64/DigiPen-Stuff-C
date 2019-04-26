/****************************
Filename: sieve.c
Name: Blakely North
Date Last Edited: 10-10-2018
Brief Description: Starting point for a yes no game
gcc -Wall -Wextra -O -ansi -pedantic -o sieve main.c sieve.c
****************************/

#include <stdio.h> /* printf      */
#include <math.h>  /* sqrt        */
#include "sieve.h" /* TRUE, FALSE */

/* this takes an array of ints of the given size and will fill it with true if the index number is prime false otherwise */
void sieve(int array[], int size)
{
  int i, j;
  /* 0 & 1 aren't prime */
  array[0] = array[1] = FALSE;
  /* loop and set all other #'s to true */
  for( i = 2 ; i <= size ; i++)
  {
    array[i] = TRUE;
  }
  /*loop through # and if still true, remove its multiples*/
  for (i = 2; i <= sqrt(size); i++)
  {
    /*check if i is prime*/
    if(array[i])
    {
      /*loop through remaining #'s and remove any multiples*/
      for (j = i+1 ; j <= size; j++)
      {
        /* check if j is divisible by i */
        if( j % i == 0)
        {
          array[j] = FALSE;
        }
      }
    }
  }
}

int twin_primes(const int primes[], int size)
{
  int i, j, totalTwins = 0;
  /*loop and see if i&j are prime*/
  for(i = 2, j = 4; j<= size; i++, j++)
  {
    if(primes[i] &&primes[j])
    {
      /*//we have a set of twin primes*/
      totalTwins++;
      printf("Twinprime #%4i: %4i and %4i\n", totalTwins, i, j);
    }
  }
  return totalTwins;
}

double brun_constant(const int primes[], int size)
{
  double bruns;
  int i, j;
  for (i =2, j = 4; j <= size; i++, j++)
  {
    if(primes[i] &&primes[j])
    {
      /* calculate bruns constant*/
      bruns += 1.0 / i + 1.0 / j;
    }

  }
  return bruns;
}

/**/
