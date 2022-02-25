#include <stdio.h>
/*
	Each runner in a relay team has a runtime t1 for how long it takes to run 100 meters starting at 0 velocity
	and a runtime t2 to run 100 meters when they've already started running

	In a 4 x 100 meter race, the first racer has to start and therefore takes t1 seconds to finish their section.
	The other four racers can take a running start and therefore take t2 seconds each.

	To determine which 4 racers should be on the team and which section they should be in,
	I first determined which members had the best t1 times and t2 times.
	I decided to search for the top 4 starters and top 5 runners. That way if there was overlap,
	I would have enough data to compensate if certain runners were better suited to starters and vice-versa

	Once I got the best of each category, I'd brute-force test each potential starter with the 3
	best runners to determine which setup would have the best overall runtime.

	The runner array has a dummy value for index 500. Its runtimes are higher than any real data
	and the dummy data is inserted into the bestRunner and bestStarter arrays to avoid issues with early insertions
*/

typedef struct runner{
	char name[22];
	double t1;
	double t2;
} runner;

runner r[501];
// these arrays refer to indices in r
// They will be in ascending order
int bestStarters[4] = {500,500,500,500};
int bestRunners[5] = {500,500,500,500,500};

// calculate the runtime of this potential setup
double calc(int *order){
	return r[order[0]].t1 + r[order[1]].t2 + r[order[2]].t2 + r[order[3]].t2;
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// determine if r[i] is one of the best runners found so far
// and determine what place they're in
// The function uses similar logic to insertion sort when determining order
void getBestRunners(int i){
	// check if r[i] is faster than the last-place best runner
	if (r[i].t2 < r[bestRunners[4]].t2){
		bestRunners[4] = i;
		// if they are, move them up until they're in sorted order
		for(int j = 4; j > 0; j--){
			if (r[bestRunners[j]].t2 < r[bestRunners[j-1]].t2){
				swap(&bestRunners[j], &bestRunners[j-1]);
			}
		}
	}
}
// same idea as getBestRunner() but for the starters
void getBestStarters(int i){
	if (r[i].t1 < r[bestStarters[3]].t1){
		bestStarters[3] = i;
		for(int j = 3; j > 0; j--){
			if (r[bestStarters[j]].t1 < r[bestStarters[j-1]].t1){
				swap(&bestStarters[j], &bestStarters[j-1]);
			}
		}
	}
}
void getBest(int n){
	int i,j,k;
	// 100 is guaranteed to be greater than what any team might get
	double res = 100, tempRes;
	int order[4], tempOrder[4];
	// get the best runners and starters
	for(i = 0; i < n; i++){
		getBestRunners(i);
		getBestStarters(i);
	}
	for(i = 0; i < 4; i++){
		// set a starter into the test order
		tempOrder[0] = bestStarters[i];
		// get the three best runners who are not the starter
		for(j = 1, k = 0; j < 4; j++, k++){
			// make sure this runner is not already the starter
			if (bestRunners[k] == bestStarters[i]){
				k++;
			}
			tempOrder[j] = bestRunners[k];
		}
		// get the runtime of this order
		tempRes = calc(tempOrder);
		// update res and order if a better team was found
		if (tempRes < res){
			res = tempRes;
			order[0] = tempOrder[0];
			order[1] = tempOrder[1];
			order[2] = tempOrder[2];
			order[3] = tempOrder[3];
		}
	}
	printf("%.10lf\n%s\n%s\n%s\n%s\n", res, r[order[0]].name, r[order[1]].name, r[order[2]].name, r[order[3]].name);
}

int main(){
	int n;

	scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %lf %lf\n", r[i].name, &(r[i].t1), &(r[i].t2));
	}
	// fill in the dummy runner with dummy values
	r[500].t1 = 20;
	r[500].t2 = 20;
	getBest(n);
}