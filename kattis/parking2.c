#include <stdio.h>

// find minimum travel distance needed to get to each point and then walk back
// since all points are along a straight line, the minimum travel distance
// is twice the distance of the two farthest points
int main(){
	int numCases, numStores;
	scanf("%d", &numCases);
	int i, j, least, greatest, temp;

	for(i = 0; i < numCases; i++){
		// get numStores and the first store
		// If only one store, it is automatically the least and greatest value
		scanf("%d\n%d", &numStores, &least);
		greatest = least;
		// find what points are furthest from each other
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