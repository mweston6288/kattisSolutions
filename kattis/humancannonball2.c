#include <stdio.h>
#include <math.h>

// Determine whether a projectile will safely pass through a hole using the given
// initial velocity, initial angle, distance from the hole, and bottom and top of the hole
// projectile needs a minimum 1m clearance from top and bottom of the hole

// change in x-coordinate formula: x(t) = v0*t*cos(deg)
// change in y-coordinate formula: y(t) = v0*t*sin(deg) - .5*9.81*t^2

// x(t) = v0*t*cos(deg)  ->  t = x(t)/(v0*cos(deg))
// the given x1 is x(t). Use it to solve for t, then use that to solve for y(t)

int main(){
	int numCases;
	scanf("%d", &numCases);

	double v0, deg, x1,h1,h2;
	int i;
	double t, yt;
	for(i = 0; i < numCases; i++){
		scanf("%lf %lf %lf %lf %lf", &v0, &deg, &x1,&h1,&h2);
		deg = deg*M_PI / 180; // convert to radians
		
		t = x1 / (v0 * cos(deg)); // determine time when projectile reaches the hole
		// determine how high off the ground projectile is at time t
		yt = v0*t*sin(deg) - 9.81*t*t*.5;
		// check if safe
		if(yt > h1+1 && yt < h2-1){
			printf("Safe\n");
		}
		else
			printf("Not Safe\n");

	}

}