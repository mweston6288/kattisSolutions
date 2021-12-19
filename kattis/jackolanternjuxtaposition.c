#include <stdio.h>

// given the cardinality of 3 sets, determine the cardinality of their cartesian product

int main(){
	int i,j,k;
	scanf("%d %d %d", &i, &j, &k);
	printf("%d\n", i*j*k);
}