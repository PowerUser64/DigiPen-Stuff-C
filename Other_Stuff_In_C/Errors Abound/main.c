/**********************
main.c
The Masked Programmer
9/23/17
Brief: This funciton demonstrates the print_cubes and print_pythagorean_ triples funcitons
gcc -Wall -Wextra -O -ansi -pedantic -o tripleCube.exe tripleCube.c main.c
*******************/

/* Function declarations */
void print_cubes(void);
void print_pythagorean_triples(int low, int high);


int main(void)
{
    /* Print all of the integers with the cube property */
  print_cubes();

    /* Print all of the triples from 1 up to 100        */
    /* but not including 100  [1, 100)  */                
  print_pythagorean_triples(1, 100);

  return 0;
}