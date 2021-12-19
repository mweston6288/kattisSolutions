#include <stdio.h>
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