#include <stdio.h>

// solve (b / a = ceiling(x)) for b when given a and x. b must be the minimum possible value

int main(){
	int a,i;
	scanf("%d %d", &a, &i);
	// since the given x is greater than the actual result of b / a
	// we decrement x by 1
	// the minimum b would be one value greater
	printf("%d\n", a * (i-1) + 1);
}