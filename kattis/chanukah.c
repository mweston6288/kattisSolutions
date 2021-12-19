#include <stdio.h>

int main(){
	int numCases, caseNum, res, i;
	scanf("%d", &numCases);
	for(i=0; i<numCases;i++){
		scanf("%d %d", &caseNum, &res);
		res = (res * (res + 1) / 2) + res;
		printf("%d %d\n", caseNum, res);
	}
}