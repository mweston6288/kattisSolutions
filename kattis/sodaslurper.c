#include <stdio.h>
/*
	e,f, and c are given integers

	(e+f) / c = q1 remainder r1
	(q1 + r1) / c = q2 remainder r2

	Repeat until qn = 0
	Return the sum of all quotients
*/

int main(){
	int e,f,c, res = 0;
	scanf("%d %d %d", &e,&f,&c);
	// some finagling is done to reduce number of variables
	while(e+f >= c){
		// get e+f
		e += f;
		// get remainder
		f = e % c;
		// get quotient
		e /= c;
		// get running total
		res+= e;
	}
	printf("%d\n", res);
}