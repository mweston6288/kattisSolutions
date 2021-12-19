#include <stdio.h>

// there are n items. Each loop, n increases either because each item duplicates or more
// items are brought in. Determine the minimum number of items created through import
// if you scan in 0, that's the end of the loops
int main(){
	int numCases, prev,current, res, i;
	scanf("%d", &numCases);
	for(i = 0; i < numCases;i++){
		// set up the baseline
		scanf("%d", &current);
		res = 0;
		while(current != 0){
			prev = current;
			scanf("%d", &current);
			// if true, some number definitely go imported
			if(current > 2*prev){
				res += current - 2*prev;
			}
		}
		printf("%d\n", res);
	}
}