#include <stdio.h>

/*
	Get the product of all non-zero digits in n. If the product has more than 1 digit, repeat.
*/

// gets the product of n's non-zero digits
int multDigits(int n){
	int res = 1,m;

	while (n > 0){
		m = n % 10;
		n /= 10;
		if (m == 0){
			continue;
		}
		res *= m;
	}
	return res;
}

int main(){
	int n;
	scanf("%d", &n);

	while(n > 9){
		n = multDigits(n);
	}
	printf("%d\n", n);
}