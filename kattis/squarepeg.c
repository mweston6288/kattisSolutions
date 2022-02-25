#include <stdio.h>
#include <math.h>
/*
	Determine if a square of length l fits in a circle of radius r
	If the length from a corner of the square to its center is less than or equal to the radius,
	the square fits

	The square can be divided into 4 right isoceles triangles with hypotenuse length l,
	two sides length d, and angles 45 degrees
	d = l*sin(pi/4) (45 degrees in radians)
	If d <= r, the square will fit
*/
int main(){
	int l,r;
	scanf("%d %d", &l, &r);
	if(sin(M_PI/4)*l <= r){
		printf("fits\n");
	}
	else{
		printf("nope\n");
	}
}