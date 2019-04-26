/********************
Ohms.c
by: Ryan Scheppler and finished by Blakely North
last edited: 11/7/2018
brief: This program is meant to use funcitons to figure out different missing pieces of circuit data.
gcc -Wall -Wextra -ansi -pedantic -O -o ohm Ohms.c
*******************/
/*NULL*/
#include <stddef.h>
/* printf */
#include <stdio.h>

#define RESNUM 10

/*Function takes 3 pointers one of which is NULL, solves for the missing values and returns what it should be. Returns -1 if something was wrong.*/
double findMissingOhmValue(double* V, double* I, double* R);

/*takes an array of resistances for parallel resistors and a given size of the array and stores the total reistance into the double pointed at by Rtotal,
can be used with as many resistances as needed in a row.*/
void findTotalResistanceParallel(double* Rtotal, double Resistor[], int size);

int main(void)
{
	/*5 volts, 2 amps*/
	double V = 5, I = 2, R;

	double Resistor[RESNUM];

	double* pV = &V;
	double* pI = &I;
	double* pR = NULL;

	int i;

	R = findMissingOhmValue(pV, pI, pR);

	printf("\nGiven a voltage of %.5f Volts, and a current of %.5f Amps, the total resistance would be %.5f Ohms\n", V, I, R);

	V = 12;
	R = 100;

	pV = &V;
	pI = NULL;
	pR = &R;

	I = findMissingOhmValue(pV, pI, pR);

	printf("Given a voltage of %.5f Volts, and a total resistance of %.5f Ohms, the current would be %.5f Amps\n", V, R, I);

	I = 0.5;
	R = 14;

	pV = NULL;
	pI = &I;
	pR = &R;

	V = findMissingOhmValue(pV, pI, pR);

	printf("Given a current of %.5f Amps, and a total resistance of %.5f Ohms, the voltage would be %.5f Volts\n", I, R, V);

	Resistor[0] = 300;
	Resistor[1] = 300;

	findTotalResistanceParallel(pR, Resistor, 2);

	printf("Total resistance is %f when R1, %f, and R2, %f, are hooked in parallel.\n", *pR, Resistor[0], Resistor[1]);

	for(i = 0; i < RESNUM; i++)
	{
		Resistor[i] = (i+1)*10;
	}
	/* run setup with first 2 then run through other parallel resistors */
	Resistor[0] = 10;
	Resistor[1] = 20;
	findTotalResistanceParallel(pR, Resistor, 2);
	printf("Total resistance is %f with resistor values 10, 20.\n", *pR);
	findTotalResistanceParallel(pR ,Resistor, RESNUM);

	printf("Total resistance is %f with resistor values 10, 20, 30, 40, 50, 60, 70, 80, 90, and 100.\n", *pR);


	/* Here try to program a test for the following circuit.
	We do not have a function for a series becausee it is just addition but you can build one if it feels worth it.
	                    |----R2---|
	5V ------R1----------         --------Ground
	                    |---R3----|
	R1 = 25 Ohms, R2 = 50 Ohms, R3 = 100 Ohms

	Make sure to print out the results!
	*/

	Resistor[0] = 50;
	Resistor[1] = 100;
	findTotalResistanceParallel(pR, Resistor, 2);
	*pR += 25;
	printf("\nThe total resistance of\n 	                            |----R2---|\n		5V ------R1----------         --------Ground\n		                    |---R3----|\n	When R1 = 25 Ohms, R2 = 50 Ohms, and R3 = 100 Ohms \n is %f.\n", *pR);



	return 0;
}
/* Fill in this function! */
/*takes an array of resistances for parallel resistors and a given size of the array and stores the total reistance into the double pointed at by Rtotal,
can be used with as many resistances as needed in a row.*/
void findTotalResistanceParallel(double* Rtotal, double Resistors[], int size)
{
	int i;
	*Rtotal = 0;
	for (i = 0; i < size; i++)
	{
		*Rtotal += 1 / Resistors[i];
	}
	*Rtotal = 1 / *Rtotal;
}
/* Fill in this function! */
/*Function takes 3 pointers one of which is NULL, solves for the missing values and returns what it should be. Returns -1 if something was wrong.*/
double findMissingOhmValue(double* V, double* I, double* R)
{
	;
	if ((V && I) || (I && R) || (R && V))
	{
		return -1;
	}
	if (V == NULL)
	{
		return (*I) * (*R);
	}
	else if (I == NULL)
	{
		return *V / *R;
	}
	else if (R == NULL)
	{
		return *V / *I;
	}
	else
		return -1;
}
