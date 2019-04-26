/********************
FileName: pi.c
Name: Blakely North
Date: 9-27-18
Brief Description: Calculates pi using variouus methods

note: -Werror treats all warnings as errors, use this when you want to make sure there are no warnings.
gcc -Wall -Wextra -Werror -O -ansi -pedantic -o pi.exe main.c pi.c
*********************/
/*sqrt*/
#include <math.h>
/* Calculates PI using a quarter circle */
double circle_pi(int rectangles)
{
	int rect_num = 1;
	double pi = 0;
	double midpoint;
	double height;
	double width = 2.0/rectangles;

	for(rect_num = 1; rect_num<=rectangles;rect_num++)
	{
		midpoint = rect_num * width - (width/2.0);
		height = sqrt(4.0-(midpoint * midpoint));
		pi+= width * height;
	}
	return pi;
}
/* Calculates PI using a series */
double leibniz_pi(int iterations)
{
	int denom = 1;
	double pi = 0;
	int i = 0; /*( iteration )*/
	int sign = 1;
	while(i<iterations)
		{
			pi += sign * (4.0 / denom);
			sign*=-1;
			denom+=2;
			i++;
		}
	/*this is to get rid of the initial unused variable warning, change what is returned and use the variable! STUB*/
	return pi;
}
