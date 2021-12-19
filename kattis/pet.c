#include <stdio.h>

int main(){
	int arr[4];
	scanf("%d %d %d %d", &arr[0],&arr[1],&arr[2],&arr[3]);
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