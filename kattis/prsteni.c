#include <stdio.h>

/*
	Find the ratio of the first number in a set to every other number in the set in lowest terms
*/
// Euclid's algorithm
int getgcd(int a,int b){
	int r;
	do{
		r = a % b;
		a = b;
		b = r;
	} while(r != 0);
	return a;
}

int main(){
	int numRings;
	scanf("%d", &numRings);
	int main, sub, gcd;
	scanf("%d", &main);
	for(int i = 1; i < numRings;i++){
		scanf("%d", &sub);
		gcd = getgcd(main, sub);
		printf("%d/%d\n", main/gcd, sub/gcd);
	}
}