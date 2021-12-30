#include <stdio.h>
#include <math.h>

/*
	Given the area of a square, find the perimeter
*/

int main(){
	// a can be as big as 10^18 so we need to use a long long rather than an int
	long long a;
	scanf("%lld", &a);
	printf("%lf\n", 4 * sqrt(a));
}