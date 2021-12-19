#include <stdio.h>

int main(){
	int numCases, numOutlets, n, i,j, res;
	scanf("%d", &numCases);
	for(i=0; i < numCases; i++){
		scanf("%d", &numOutlets);
		res = 0;
		for(j=0; j < numOutlets;j++){
			scanf("%d", &n);
			res += n;
		}
		printf("%d\n", res - numOutlets + 1);
	}
}