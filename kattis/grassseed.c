#include <stdio.h>
// given a price value and a set of lawns with their own dimensions
// determine the cost price to work on each lawn
int main(){
	double price,l,w, cost = 0;
	int numLawns,i;
	scanf("%lf %d", &price, &numLawns);
	for(i = 0; i < numLawns;i++){
		scanf("%lf %lf", &l, &w);
		cost += (price * l * w);
	}
	printf("%.8lf\n", cost);
}