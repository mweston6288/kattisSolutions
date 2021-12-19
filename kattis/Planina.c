#include <stdio.h>

// given a square, how many intersections are created when you divide that square into 4 squares
// and then those squares into 4 squares, and repeat n times

// recursive. f(n) = g(n)^2, g(0) = 2, g(n) = g(n-1) + 2^(n-1)
int main(){
	int n;
	scanf("%d", &n);
	int i, incrementor = 1, res = 2;
	// res is g(n-1)
	// incrementor is 2^(n-1)
	for(i = 1; i <= n; i++){
		res += incrementor; 
		incrementor *= 2;
	}
	printf("%d\n", res * res);
}