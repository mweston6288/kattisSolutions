#include <stdio.h>
#include <stdlib.h>

// given 3 integers, determine if the first two can be arithmetically combined to make the third one
int main(){
	int a,b,c, numCases;
	scanf("%d", &numCases);

	for(int i = 0; i < numCases; i++){
		scanf("%d %d %d", &a, &b, &c);
		// check if sum, difference, product, or quotient of a and b = c
		// diff can be simplified with abs, quotient needs a mod check because of int division
		if (a+b == c || abs(a-b) == c || a*b == c || (a%b == 0 && a/b == c) || (b%a == 0 && b/a == c))
			printf("Possible\n");
		else
			printf("Impossible\n");

	}
}