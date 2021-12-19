#include <stdio.h>

// given the number of values in a set and a subset of those values,
// determine the minimum and maximum possible average if the values rage from [-3,3]

int main(){
	int numJudges, numRatings, score, i;
	double sum=0;
	scanf("%d %d", &numJudges, &numRatings);
	// get sum of knowns
	for(i=0; i < numRatings;i++){
		scanf("%d", &score);
		sum += score;
	}
	// fill in the unknowns with the smallest or greatest possible value
	printf("%lf %lf\n", (sum + -3*(numJudges - numRatings)) / numJudges, (sum + 3*(numJudges - numRatings)) / numJudges);

}