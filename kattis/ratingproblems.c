#include <stdio.h>

int main(){
	int numJudges, numRatings, score, i;
	double sum=0;
	scanf("%d %d", &numJudges, &numRatings);
	for(i=0; i < numRatings;i++){
		scanf("%d", &score);
		sum += score;
	}
	printf("%lf %lf\n", (sum + -3*(numJudges - numRatings)) / numJudges, (sum + 3*(numJudges - numRatings)) / numJudges);

}