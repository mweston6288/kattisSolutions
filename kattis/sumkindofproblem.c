#include <stdio.h>

/*
	sum from 1 to n = n*(n+1)/2
	
	definition of odd integer: there exists an int c such that 2c+1 = n
	nth odd positive int = 2n-1
	sum of n odd ints
		= 0*2+1 + 1*2+1 + 2*2+1 +...+ 2(n-1)+1
		= 2(0+1+2+...+(n-1)) + n
		= 2((n-1)*(n)/2) + n
		= (n-1)*n + n
		= n(n-1+1)
		= n^2
	
	definition of even integer: there exists an int c such that 2c = n
	nth even positive integer = 2n
	sum of n even ints
		= 2*1 + 2*2 + 2*3 +...+2n
		= 2(1+2+3+...+n)
		= 2(n(n+1)/2)
		= n(n+1)
*/

int main(){
	int numCases;
	scanf("%d", &numCases);
	int i, k, n;
	for(i=0;i<numCases;i++){
		scanf("%d %d", &k, &n);
		printf("%d %d %d %d\n", k, n*(n+1)/2, n*n, n*(n+1));
	}
}