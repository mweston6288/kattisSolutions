#include <math.h>
#include <stdio.h>

/*
	Given a circle with radius r set perfectly inside a square such that the circle is tangent to each side,
	and given a number of marks inside the square, m, along with how many of those marks are also in the circle, c,
	determine the true area of the circle and an estimate based on the proportion of marks in and out of the circle

	c/m gives us the proportion of marks inside the circle vs total amount
	We then need to calculate the square's area. Since we're given the circle's radius, we just solve
	(r*2) * (r*2) = r*r*4
	Then divide the area by c/m
*/

int main(){
	double r,m,c;
	// we're given multiple test cases with values 0 0 0 being the cut-off point
	while(1){
		scanf("%lf %lf %lf", &r,&m,&c);
		// r must always be >0 so just check if r=0 to know whether to continue
		if(!r){
			break;
		}
		printf("%lf %lf\n", M_PI*r*r, r*r*4*(c/m));
	}
}