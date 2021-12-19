#include <stdio.h>

int main(){
	int numCases, n,i;
	scanf("%d", &numCases);
	for(i = 0; i < numCases; i++){
		scanf("%d", &n);
		printf("%d is %s\n", n, n % 2 == 0 ? "even" : "odd");
	}
}