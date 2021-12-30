#include <stdio.h>
#include <math.h>
/*
	f(1) = 1, f(x) = 2*f(x-1) + 1 for x > 1. Find f(x) for a given input x

	functionally, f(x) can be rewritten as f(x) = 2^x - 1 for x >= 1.

*/

int main(){
	int numCases, numStops;
	scanf("%d", &numCases);
	for(int i = 0; i < numCases;i++){
		scanf("%d", &numStops);
		printf("%d\n", ((int)pow(2, numStops))-1);
	}
}