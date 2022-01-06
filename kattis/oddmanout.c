#include <stdio.h>
/*
	Find the number in each set that only appears once. bitwise XOR is the solution here.
*/
int main(){
	int numCases;
	int g, i, j, res;
	scanf("%d", &numCases);

	for(i = 1; i <= numCases;i++){
		res = 0;
		scanf("%d", &j);
		for(;j>0;j--){
			scanf("%d", &g);
			res ^= g;
		}
		printf("Case #%d: %d\n", i, res);
	}
}