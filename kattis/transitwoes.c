#include <stdio.h>
#include <stdlib.h>

/*
	Determine with the given information whether you would arrive to class on time
	by taking the various bus rides

	You are given the time you start traveling, the time the class starts, and how many buses to ride
	Then you are given the time to walk from point to point
	Then you are given travel time on each bus
	Then you are given the time interval each bus arrives at the bus stop
*/
int main(){
	int curr, arr, numBuses, i;
	int *walkTimes, *travelTimes, *intervals;

	scanf("%d %d %d", &curr, &arr, &numBuses);
	
	walkTimes = malloc(sizeof(int)*(numBuses+1));
	travelTimes = malloc(sizeof(int)*numBuses);
	intervals = malloc(sizeof(int)*numBuses);
	// read in all data
	for(i = 0 ; i <= numBuses; i++){
		scanf("%d", &walkTimes[i]);
	}
	for(i = 0 ; i < numBuses; i++){
		scanf("%d", &travelTimes[i]);
	}
	for(i = 0 ; i < numBuses; i++){
		scanf("%d", &intervals[i]);
	}

	
	// for each stop, walk to destination, wait for bus, ride it
	for(i = 0; i < numBuses;i++){
		curr += walkTimes[i];
		// if true, you missed the bus. Wait for the next one
		if (curr % intervals[i] != 0){
			curr += intervals[i] - (curr % intervals[i]);
		}
		curr += travelTimes[i];
	}

	// final step: walk to class
	curr += walkTimes[i];
	if(curr <= arr){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	free(walkTimes);
	free(travelTimes);
	free(intervals);
}