#include <stdio.h>

int main(){
	int numCases, prev,current, res, i;
	scanf("%d", &numCases);
	for(i = 0; i < numCases;i++){
		scanf("%d", &current);
		res = 0;
		while(current != 0){
			prev = current;
			scanf("%d", &current);
			if(current > 2*prev){
				res += current - 2*prev;
			}
		}
		printf("%d\n", res);
	}
}