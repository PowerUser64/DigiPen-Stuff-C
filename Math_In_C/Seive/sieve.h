/****************************
Filename: sieve.h
Name: Blakely North
Date Last Edited: 10-10-2018
Brief Description: Starting point for a yes no game
gcc -Wall -Wextra -O -ansi -pedantic -o sieve sieve.h
****************************/
#define FALSE 0
#define TRUE  1

void sieve(int array[], int size);
int twin_primes(const int primes[], int size);
double brun_constant(const int primes[], int size);
