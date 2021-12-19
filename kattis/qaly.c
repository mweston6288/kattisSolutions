#include <stdio.h>

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