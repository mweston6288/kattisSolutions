#include <stdio.h>

// given the number of heart beats in a given time range, determine bpm and the min and max range of actual bpm
// bpm = 60b/p, range = 60/t
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