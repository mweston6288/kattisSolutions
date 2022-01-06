#include <stdio.h>
/*
	Despite how complex the problem looks, it's ultimately asking how many edges are needed to make a
	spanning tree. SInce I'm given the number of nodes in the graph , I just need to return that number - 1.
	The rest of the data is garbage.
*/
int main(){
	int numCases, numNodes, numEdges,junk,i,j;
	scanf("%d", &numCases);
	for(i = 0; i < numCases;i++){
		scanf("%d %d", &numNodes, &numEdges);
		// print the only important thing
		printf("%d\n", numNodes - 1);
		// filter out all the junk
		for(j = 0; j < numEdges;j++){
			scanf("%d %d", &junk, &junk);
		}
	}
}