#include <stdio.h>
/*
	This problem is secretly asking you to find the n-1th and nth fibonnachi numbers
*/
int main(){
	int n;
	// gonna store the fib sequence in an array
	int fib[46];
	fib[0] = 0;
	fib[1] = 1;
	scanf("%d", &n);
	// fill in the array up to n
	for(int i = 2; i <= n;i++){
		fib[i] = fib[i-1] +fib[i-2];
	}
	printf("%d %d\n", fib[n-1], fib[n]);
}