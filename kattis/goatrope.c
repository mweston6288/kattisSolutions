#include <stdio.h>
#include <math.h>
/*
	Given the center of a circle (x,y) and two diagonally opposite coordinates of a rectangle ( (x1,y1), (x2,y2) ),
	determine the radius of the circle which will make it tangent to the rectangle

	The first rectangle coordinate will always be the lower left corner
	The second coordinate will always be the top right


	Broadly speaking, there are only two things to consider:
		Whether x is in [x1,x2]
		Whether y is in [y1,y2]
	
	If both are false, then the radius is diagonal to a corner of the rectangle, so you need
	to find the distance to the nearest corner

	If one is true, then the radius is a horizontal or vertical line to the nearest side of the
	rectangle
	
	Distance from (x1,y1) to (x2,y2) = sqrt((x1-x2)^2 + (y1-y)^2)


*/
int main(){
	int x,y, x1,y1,x2,y2;
	scanf("%d %d %d %d %d %d", &x,&y, &x1,&y1,&x2,&y2);

	int dist1,dist2;
	// determine x-coordinate distance
	if(x < x1){
		dist1 = x1-x;
	}
	else if(x > x2){
		dist1 = x - x2;
	}
	// if true, circle is above or below the rectangle and we only need the y-coordinate
	else{
		dist1 = 0;
	}
	// determine y-coordinate distance
	if(y < y1){
		dist2 = y1-y;
	}
	else if(y > y2){
		dist2 = y - y2;
	}
	// if true, circle is left or right of the rectangle and we only need the x-coordinate
	else{
		dist2 = 0;
	}

	printf("%lf\n", sqrt(dist1*dist1 + dist2*dist2));

}