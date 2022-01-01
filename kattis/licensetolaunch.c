#include <stdio.h>

/*
	Given an array of ints, determine which index has the smallest value
	If there's a tie, print the smaller index
*/

int main(){
	int numCases, i, min,n, res = 0;
	scanf("%d %d", &numCases, &min);

	for(i = 1;i <numCases;i++){
		scanf("%d", &n);
		if (n < min){
			res = i;
			min = n;
		}
	}
	printf("%d\n", res);
}