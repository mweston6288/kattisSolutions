#include <stdio.h>
/*
	Get the last digit of N!

	Rather than doing any actual math, this can be easily hardcoded
	when n >= 5, n! is divisible by 10, so the last digit will be 0
	As for the other values:
		0! = 1, 1! = 1, 2! = 2, 3! = 6, 4! = 24
	So I have to specify when n = 0 and n = 3, but for n = 1,2,or 4 I can just print n
*/
int main(){
	int numCases;
	scanf("%d", &numCases);
	int num;
	for(int i = 0; i < numCases; i++){
		scanf("%d", &num);
		if (num >=5){
			printf("0\n");
		}
		else if (num == 3){
			printf("6\n");
		}
		else if(num == 0){
			printf("1\n");
		}
		else{
			printf("%d\n", num);
		}
	}
}