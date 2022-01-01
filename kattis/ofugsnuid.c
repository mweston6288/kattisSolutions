#include <stdio.h>
#include <stdlib.h>
/*
	Take in a set of integers and print them in reverse order
*/
int main(){
	int num;
	scanf("%d", &num);
	
	int *nums = malloc(sizeof(int)*num);

	int i;
	// read them in
	for(i = 0; i< num;i++){
		scanf("%d", &nums[i]);
	}
	// print them out
	for(i = num - 1; i >=0; i--){
		printf("%d\n", nums[i]);
	}
}