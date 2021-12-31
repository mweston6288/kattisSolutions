#include <stdio.h>
#include <math.h>
/*
	Given a real number N, find a real a such that the infinite tetration of a = n
	a^(a^(a^(a^...))) = N

	Apparantly, if there is a solution, it's n^(1/n).
*/
int main(){
	double n;
	scanf("%lf", &n);

	printf("%lf\n", pow(n, 1/n));
}