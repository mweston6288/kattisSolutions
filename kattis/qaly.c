#include <stdio.h>

// given n pairs of numbers, get the sum of the product of each pair

int main(){
	int numPer, i;
	double res = 0, qol, years;

	scanf("%d", &numPer);
	for(i = 0; i < numPer;i++){
		scanf("%lf %lf", &qol, &years);
		res += qol * years;
	}
	printf("%lf\n", res);


}