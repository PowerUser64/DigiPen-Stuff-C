/******************************************************************************
Filename: array.c
Author: Blakely North
Date: 10-22-18
Brief Description: This is the math that powers the other two c files
gcc -Wall -Wextra -O -ansi -pedantic -o array main1.c array.c
******************************************************************************/

/* frusterate */
void reverse_array(int a[], int size)
{
  int i, temp2, temp, csize;
  int hsize = size/2;
  for (i = 0, csize = size-1; i < hsize; ++i, --csize)
  {
    a[i] = a[csize];
    a[csize] = a[i];
  }
}

/**/
void add_arrays(const int a[], const int b[], int c[], int size)
{
  int i;
  for (i = 0; size > i ; i++)
  {
    c[i] = a[i] + b[i];
  }
}

/**/
void scalar_multiply(int a[], int size, int multiplier)
{
  int i = 0;
  for (; size > i; i++)
  {
    a[i] *= multiplier;
  }
}

/**/
int dot_product(const int a[], const int b[], int size)
{
  int i = 0;
  int result = 0;
  for (; i < size; i++)
  {
    result += a[i] * b[i];
  }
}

/**/
void cross_product(const int a[], const int b[], int c[])
{
  /* check if each variable is above 2 if so set to 0 */

  c[0] = a[1]*b[2] - a[2]*b[1];

  c[1] = -(b[2]*a[0] - b[0]*a[2]);

  c[2] = a[0]*b[1] - a[1]*b[0];
}
