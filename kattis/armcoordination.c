#include <stdio.h>
/*
	Given a circle at coordinate (x,y) with radius r, determine the coordinates of the corners of the smallest
	square that can fit the circle.

	The sides of the square need to be length 2r. The circle and square will touch at the halfway point of each
	side of the circle.

	Easiest square to calculate is one whose corner coordinates are all (x,y) +/- r
*/
int main(){
	int x,y,r;
	scanf("%d %d %d", &x, &y, &r);
	printf("%d %d\n", x+r, y+r);
	printf("%d %d\n", x+r, y-r);
	printf("%d %d\n", x-r, y-r);
	printf("%d %d\n", x-r, y+r);
}