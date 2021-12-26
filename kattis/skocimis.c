#include <stdio.h>
/*
	Given three items along a numberline, determine the maximum number of times you can move
	one of the outer items between the other two until they are all adjacent

	This can be determined by checking the distance from both of the outer items to the inner item
	and getting the greater distance - 1
*/

int main(){
	int a,b,c;
	scanf("%d %d %d", &a,&b,&c);
	int diffab = b-a;
	int diffbc = c-b;
	if (diffbc < diffab){
		printf("%d\n", diffab - 1);
	}
	else{
		printf("%d\n", diffbc - 1);
	}
}