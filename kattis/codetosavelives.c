#include <stdio.h>
/*
	add two integers that have spaces between each digit
	print the result with a space between each digit
*/
// print the result with spaces between each digit
void printWithSpaces(int n){
	// base case: single digit n, just print it
	if(n < 10){
		printf("%d", n);
		return;
	}
	// recursively divide n by 10 to get to the MSD
	printWithSpaces(n / 10);
	// print a space and next digit
	printf(" %d", n % 10);
}
int main(){
	int m,n, numCases;
	int i,j;
	scanf("%d", &numCases);

	for(i = 0; i < numCases;i++){
		m = 0;
		n = 0;
		// get the first number
		// in each cycle, move each digit over by 1,
		// insert the next digit and check if there's a space
		// or line break
		do{
			scanf("%d", &j);
			m *= 10;
			m += j;
			j = fgetc(stdin);
		}
		while(j == ' ');
		// do the same for the second number
		do{
			scanf("%d", &j);
			n *= 10;
			n += j;
			j = fgetc(stdin);
		}
		while(j == ' ');
		printWithSpaces(m+n);
		printf("\n");
	}
}