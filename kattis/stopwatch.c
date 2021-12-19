#include <stdio.h>

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