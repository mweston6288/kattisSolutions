#include <stdio.h>
/*
	Given a number of junctions x (connects to four pieces, forming an x) and the number of switches y
	(connects to 3 pieces, forming a y), determine if you could make a closed railroad system

	All thatr matters is there is an even number of switches.
	A closed railroad system requires an even number of endpoints. 
	A non-switch, non-junction piece has two endpoints. Adding a junction creates two additional endpoints
	Adding a switch adds only 1 additional endpoint. SO you can have as many or as few junctions,
	but must have an even number of switches
*/
int main(){
	int x,y;
	scanf("%d %d", &x,&y);
	if (y % 2 == 0){
		printf("possible\n");
	}
	else{
		printf("impossible\n");
	}
}