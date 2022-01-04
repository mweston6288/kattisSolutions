#include <stdio.h>
/*
	The actual question is "Is the passed in number even or odd"
	If you have a branch of length n, you can only break it into n 1-unit pieces and it always takes n - 1 steps
*/
int main(){
	int n;
	scanf("%d", &n);

	if(n & 1){
		printf("Bob\n");
	}
	else {
		printf("Alice\n1\n");
	}
}