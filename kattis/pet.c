#include <stdio.h>
// Given 20 numbers in 5 groups of 4, add up the numbers in each group and determine which group has the highest sum
int main(){
	int arr[4];
	// scan in 4 numbers at a time, sum them up and store the biggest result
	scanf("%d %d %d %d", &arr[0],&arr[1],&arr[2],&arr[3]);
	// first group is the baseline
	int maxScore = arr[0]+arr[1]+arr[2]+arr[3];
	int winner = 1;
	int i,score;
	for(i = 2; i<=5; i++){
		scanf("%d %d %d %d", &arr[0],&arr[1],&arr[2],&arr[3]);
		score = arr[0]+arr[1]+arr[2]+arr[3];
		if (score > maxScore){
			maxScore = score;
			winner = i;
		}
	}
	printf("%d %d\n", winner, maxScore);
}