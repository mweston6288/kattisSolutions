#include <stdio.h>
/*
	In a list of n numbers, print every kth one on a single line
*/
int main(){
	int n,k,i,j,x;
	scanf("%d %d", &n, &k);

	// get and print the first number
	// scan through k numbers and print the first result
	for(j = 0; j < k; j++){
		scanf("%d", &x);
	}
	printf("%d", x);

	i = k;
	// while there are still at least k numbers
	// print the rest
	while (i+k <= n){
		for(j = 0; j < k; j++){
			scanf("%d", &x);
		}
		printf(" %d", x);
		i += k;
	}
	printf("\n");

}