#include <stdio.h>

// given a coordinate, determine the quadrant on an xy plane it would be on

int main(){
	int x,y;
	scanf("%d %d", &x, &y);
	if (x > 0){
		if (y > 0){
			printf("1\n");
		}
		else{
			printf("4\n");
		}
	}
	else{
		if (y > 0){
			printf("2\n");
		}
		else{
			printf("3\n");
		}
	}
}