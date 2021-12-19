#include <stdio.h>

// This is getting an average but also removing certain invalid values
int main(){
	int bases;
	double sum=0;
	int t, i, n;
	
	scanf("%d", &bases);
	n = bases; // bases will decrement every time we find an invalid entry
	for(i = 0; i < n; i++){
		scanf("%d", &t);
		// bad entry. Remove it from the equation
		if (t == -1){
			bases--;
			continue;
		}
		sum += t;
	}
	// print average
	printf("%lf\n", sum / bases);
}