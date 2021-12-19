#include <stdio.h>

// given two three-digit numbers, reverse the order of the digits and print the greater resulting value
// in order to speed things up, I cheat at this a bit. I print the answer as I determine what it is

// this prints the remaining digits once I know the final answer
void printRemainder(int n){
	while (n != 0){
		printf("%d", n % 10);
		n /= 10;
	}
	printf("\n");
}

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	int compA = a % 10, compB = b % 10;
	// If compA and compB match, the final answer will include that value
	// so I'll just print it out while I have it
	while(compA == compB){
		printf("%d", compA);
		a /= 10;
		b /= 10;
		compA = a % 10;
		compB = b % 10;
	}
	// once I know which value is the answer, I print the remaining digits
	printRemainder(compA > compB ? a: b);
}