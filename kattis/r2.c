#include <stdio.h>

// given a number and the mean of that number and another, determine the second number
// (r1+r2) / 2 = s  ->   2s - r1 = r2

int main(){
	int r1, s;
	scanf("%d %d", &r1,&s);
	printf("%d\n", 2*s - r1);
}