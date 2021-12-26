#include <stdio.h>

/*
	Given a set of integers, determine the absolute value of the sum of all the negative integers
*/

int main(){
	int num, total = 0, i, input;
	scanf("%d", &num);
	for(i = 0; i < num; i++){
		scanf("%d", &input);
		if (input < 0){
			total += input;
		}
	}
	printf("%d\n", -total);
}