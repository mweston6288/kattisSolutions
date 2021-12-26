#include <stdio.h>

/*
	Given a set of speeds at time t and the time checked, determine roughly how far a vehicle traveled
	t is continually increasing so I must subtract the previous value of t each time
	Input of -1 indicates end of inputs
*/

int main(){
	// There is guaranteed to be at least 1 set
	// go through the initial setup
	int numData;
	scanf("%d", &numData);
	int i, mph,prevH,currH, res;

	while(numData != -1){
		scanf("%d %d", &mph,&currH);
		// initialize res as total distance traveled at the first timepoint
		res = mph*currH;
		for(i = 1; i < numData;i++){
			prevH = currH;
			scanf("%d %d", &mph,&currH);
			res += mph*(currH - prevH);
		}
		printf("%d miles\n", res);
		// scan the next value of numData to determine if we're running again
		scanf("%d", &numData);

	}
}