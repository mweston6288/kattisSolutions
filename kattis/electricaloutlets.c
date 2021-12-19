#include <stdio.h>

// given a number of power strips, each with their own number of outlets,
// determine how many appliances can be plugged into a single outlet.
// This assumes the circuit breaker won't trip
int main(){
	int numCases, numOutlets, n, i,j, res;
	scanf("%d", &numCases);
	for(i=0; i < numCases; i++){
		scanf("%d", &numOutlets);
		res = 1; // one for the wall outlet
		for(j=0; j < numOutlets;j++){
			scanf("%d", &n);
			res += n;
		}
		// For each power strip added, one available outlet must be used to
		// plug in the strip
		printf("%d\n", res - numOutlets);
	}
}