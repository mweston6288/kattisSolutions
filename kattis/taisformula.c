#include <stdio.h>
/*
	Calculate the area under a curve as a measure of time

	t is in milliseconds but the answer has to be in seconds
*/
int main(){
	int numCases;
	scanf("%d", &numCases);

	int t1,t2;
	double v1,v2;
	double res = 0;
	scanf("%d %lf", &t2, &v2);
	for(int i = 1; i < numCases; i++){
		t1 = t2;
		v1 = v2;
		scanf("%d %lf", &t2, &v2);
		res += (v1+v2)/2 *((t2 - t1) / 1000.0);
	}
	printf("%lf\n", res);
}