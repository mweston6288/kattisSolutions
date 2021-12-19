#include <stdio.h>

// pseudo recursive. f(n) = g(n)^2, g(0) = 2, g(n) = g(n-1) + 2^(n-1)
int main(){
	int n;
	scanf("%d", &n);
	int i, incrementor = 1, res = 2;

	for(i = 1; i <= n; i++){
		res += incrementor;
		incrementor *= 2;
	}
	printf("%d\n", res * res);
}