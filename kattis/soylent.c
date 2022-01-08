#include <stdio.h>
/*
	return ceil(n / 400)
*/
int main(){
	int numCases,n;
	scanf("%d", &numCases);
	for(int i = 0; i < numCases;i++){
		scanf("%d", &n);
		printf("%d\n", n % 400 == 0 ? n / 400 : n / 400 + 1);
	}
}