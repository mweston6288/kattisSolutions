#include <stdio.h>
/*
	Determine the ratio of a betting payout of two options when given 
	the percent of the total pool placed into option 1
	The poerecent is given as a whole number

	If x is a percent of the total pool, then the pool is equal to 1/x
*/
int main(){
	double m, n;
	scanf("%lf", &m);
	// convert to percent
	m /= 100;
	// calcutate the contribution of the second pool
	n = 1 - m;
	printf("%.9lf\n%.9lf\n", 1 / m, 1 / n);
}