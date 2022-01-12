#include <stdio.h>

/*
	Determine which 7 of 9 numbers sum to 100

	Solution process: Get the sum of all 9, then test each pair to see if they equal the exces. Print the rest

	They have to be printed in original order, so no sorting allowed.
*/
// i and j are the indices to skip
void print(int *arr, int i, int j){
	int k;
	// print everything before the first skipped index
	for(k = 0; k < i;k++){
		printf("%d\n", arr[k]);
	}
	// print everything between the two skipped indices
	for(k += 1; k < j;k++){
		printf("%d\n", arr[k]);
	}
	// print everything after the second skipped index
	for(k += 1; k < 9;k++){
		printf("%d\n", arr[k]);
	}
}
int main(){
	int n[9];
	int tot = 0;
	int l,m;
	int i,j;
	// get the numbers and total
	for(i = 0; i < 9;i++){
		scanf("%d", &n[i]);
		tot += n[i];
	}
	// get the excess
	tot -= 100;

	// start brute force testing each pair
	for(i = 0; i < 8;i++){
		for(j = i+1; j < 9;j++){
			// match found. Print and exit
			if(n[i] + n[j] == tot){
				print(n, i,j);
				return 0;
			}
		}
	}
}