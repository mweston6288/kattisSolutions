#include <stdio.h>

// at t=0, a stopped stopwatch is reading 0s
// given a set of values for t, determine what the stopwatch reads if it is pressed at each time
// if the stopwatch is still running, indicate that instead

int main(){
	int numPresses, prev, cur, res = 0;
	scanf("%d", &numPresses);

	// get initial press
	scanf("%d", &cur);
	short running = 1;

	for(int i = 1; i < numPresses;i++){
		prev = cur;
		scanf("%d", &cur);
		// running is 0 if not running
		res += (cur - prev) * running;
		running = running ^ 1;
	}
	if (!running){
		printf("%d\n", res);
	}
	else{
		printf("still running\n");
	}
}