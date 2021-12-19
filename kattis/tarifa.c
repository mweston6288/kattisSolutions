#include <stdio.h>

// given the data plan allowances for a month and data used each month, 
// determine available data for next month

// remMB will store the maximum possible data
// assuming none was used during the entire period
// then I'll subtract the data used each month
int main(){
	int remMB;
	int months, i, x;
	scanf("%d %d", &remMB, &months);
	// get max possible data
	remMB = remMB * (months + 1);
	// start subtracting used data
	for (i = 0; i < months; i++){
		scanf("%d", &x);
		remMB -= x;
	}
	printf("%d\n", remMB);
}