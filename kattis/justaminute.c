#include <stdio.h>
/*
	Given a set of minutes and a set of seconds, find the ratio of the averages of the seconds to the minutes
*/
int main(){
	int numCases;
	// ints are passed in, but the output has to be a real number
	double m=0,n=0;
	double a,b;

	scanf("%d", &numCases);
	for(int i = 0; i < numCases; i++){
		// get sum of minutes and seconds
		scanf("%lf %lf", &a, &b);
		m += a;
		n += b;
	}
	// convert minutes to seconds
	m *= 60;
	// get average of both groups
	m /= numCases;
	n /= numCases;
	// get ratio
	n /= m;
	if(n <= 1.0){
		printf("measurement error\n");
	}
	else{
		printf("%.10lf\n", n );

	}
}