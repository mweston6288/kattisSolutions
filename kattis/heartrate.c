#include <stdio.h>

int main(){
	int numCases;
	int beats, i;
	double seconds;
	double range, bpm;

	scanf("%d", &numCases);
	for (i = 0; i < numCases; i++){
		scanf("%d %lf", &beats, &seconds);
		range = 60 / seconds;
		bpm = 60*beats / seconds;
		printf("%lf %lf %lf\n", bpm - range, bpm, bpm + range);
	}
}