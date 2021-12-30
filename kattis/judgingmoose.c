#include <stdio.h>
/*
	Given the number of tines on a moose's antlers determine its age

	There are three cases:
	If the number of tines on both antlers is equal, add them together
	If the number of tines on both antlers is different, take the larger value and multiply it by 2
	If there are no tines at all, it's not a moose
*/
int main(){
	int l,r;
	scanf("%d %d", &l, &r);
	if (l == 0 && r == 0){
		printf("Not a moose\n");
	}
	else if (l == r){
		printf("even %d\n", 2*l);
	}
	else if (l < r){
		printf("odd %d\n", 2*r);
	}
	else{
		printf("odd %d\n", 2*l);
	}
}