#include <stdio.h>

/*
	Given a snapshot series of total distance traveled at various points in time, determine
	the maximum speed traveled over the entire timeframe

	Solution is determined by dividing the difference between two adjacent distance snapshots
	by the difference of their time snapshots
*/

int main(){
	int numData;
	scanf("%d", &numData);

	int i, currT,currD, prevT, prevD, maxSpeed = 0, currSpeed;
	// initialize the data with the first set
	scanf("%d %d", &currT, &currD);

	for(i = 1; i < numData;i++){
		prevT = currT;
		prevD = currD;
		scanf("%d %d", &currT, &currD);
		// determine the average speed traveled in this interval
		currSpeed = (currD - prevD) / (currT - prevT);
		if(currSpeed > maxSpeed){
			maxSpeed = currSpeed;
		}
	}
	printf("%d\n", maxSpeed);
}