#include <stdio.h>

/*
	Given a number and a base, determine the sum of the square of that number's digits after converting it to the base
*/

// this does the legwork
int SSD(int b, int n){
	int res = 0;

	while (n > 0){
		// convert n to base b. Along the way, get the square of each processed digit
		res += (n%b) *(n%b);
		n /= b;
	}
	return res;
}

int main(){
	int numCases;
	scanf("%d", &numCases);
	int b,n;

	for(int i = 1; i <= numCases;i++){
		scanf("%d %d %d", &n, &b,&n);
		printf("%d %d\n",i, SSD(b,n));
	}
}