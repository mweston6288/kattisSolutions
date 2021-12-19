#include <stdio.h>

// find minimum travel distance needed to get to each point and then walk back
// since all points are along a straight line, the most optimal strategy is to start
// exactly at the furthest of one end. Travel to the other end, and then travel back
int main(){
	int numCases, numStores;
	scanf("%d", &numCases);
	int i, j, least, greatest, temp;

	for(i = 0; i < numCases; i++){
		// gen numStores and the first store
		// If only one store, it is automatically the least and greatest value
		scanf("%d\n%d", &numStores, &least);
		greatest = least;
		for(j = 1; j < numStores; j++){
			scanf("%d", &temp);
			if(temp < least){
				least = temp;
			}
			else if(temp > greatest){
				greatest = temp;
			}
		}
		printf("%d\n", (greatest - least) * 2);
	}
}