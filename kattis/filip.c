#include <stdio.h>


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
	while(compA == compB){
		printf("%d", compA);
		a /= 10;
		b /= 10;
		compA = a % 10;
		compB = b % 10;
	}
	printRemainder(compA > compB ? a: b);
}