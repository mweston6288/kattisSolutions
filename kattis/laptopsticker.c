#include <stdio.h>

/*
	Given the dimensions of two rectangles c and s, determine if s can fit into c without rotation
	and have at least a 1 unit pargin on all sides
*/

int main(){
	int wc,hc,ws,hs;
	scanf("%d %d %d %d", &wc,&hc,&ws,&hs);
	// the +2 if for the margin on each side
	if (ws + 2 <= wc && hs + 2 <= hc)
		printf("1\n");
	else
		printf("0\n");
}