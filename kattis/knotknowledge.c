#include <stdio.h>
/*
	Given two sets of numbers that are exactly the same except the second is missing one number in the first,
	determine which number is missing

	Easiest solution is using bitwise XOR. Since a XOR a = 0, the remaining value after
	using XOR on both sets will be the missing value
*/
int main(){
	int num, res = 0, i,j;
	scanf("%d", &num);
	// initial value ensures both sets are read in over the course of this loop
	for(i = 1-num; i < num;i++){
		scanf("%d", &j);
		res ^= j;
	}

	printf("%d\n", res);
}