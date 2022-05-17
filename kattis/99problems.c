#include <stdio.h>
/*
	Round a given positive integer to the nearest positive integer that ends in 99. Round up
	if there are two equally near values
*/
int main(){
	int n;
	scanf("%d", &n);
	int mod = n % 100;
	// Round up if n ended in at least 49 or was less than 100 (to avoid returning a negative number)
	if(mod >= 49 || n < 100){
		printf("%d\n", n + 99 - mod);
	}
	else{
		printf("%d\n", n - 1 - mod);
	}
}