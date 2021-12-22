#include <stdio.h>

// Given three integers, x,y, and n, print all integers in range [1,n] 
// but print "Fizz" instead of any number divisible by x, "Buzz" instead of any number divisible by y
// and FizzBuzz for any number divisible by both

int main(){
	int x,y,z,n,i;
	scanf("%d %d %d", &x,&y,&n);
	for(i = 1; i <=n; i++){
		if(i % x == 0){
			printf("Fizz");
			// check if Buzz should follow
			if(i % y == 0){
				printf("Buzz");
			}
			printf("\n");
		}
		else if(i % y == 0){
			printf("Buzz\n");
		}
		else {
			printf("%d\n", i);
		}
	}
}