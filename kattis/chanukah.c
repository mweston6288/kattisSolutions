#include <stdio.h>

// For each case, determine the total number of candles lit
// pattern is 2+3+4+...+(n+1).
// summation of i=1 to n of i = n(n+1)/2
// so the formula for this is n(n+1)/2 + n
int main(){
	int numCases, caseNum, res, i; // res will both store the number of days and number of candles lit
	scanf("%d", &numCases);
	for(i=0; i<numCases;i++){
		scanf("%d %d", &caseNum, &res);
		res = (res * (res + 1) / 2) + res;
		printf("%d %d\n", caseNum, res);
	}
}