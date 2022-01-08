#include <stdio.h>
/*
	Given a set of integers where all but one are equal to the previous value +1,
	determine which one is not following that pattern
*/
int main(){
	int numCases, n, prev,curr,j;
	scanf("%d", &numCases);
	for(int i = 0; i < numCases;i++){
		scanf("%d %d", &n, &curr);
		// find the bad index
		for(j = 2; j < n; j++){
			prev = curr;
			scanf("%d", &curr);
			// found it
			if(curr - prev != 1){
				printf("%d\n", j);
				break;
			}
		}
		// burn up all the other values for the next round
		for(; j< n;j++){
			scanf("%d", &curr);
		}
	}
}