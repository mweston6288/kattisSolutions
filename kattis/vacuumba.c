#include <stdio.h>
#include <math.h>
/*
	An object starting at origin and facing in the positive y-direction rotates at an angle
	and then moves forward a certain distance. The object repeats this several times.
	Find the final coordinate location of the object.

	Since it faces the positive y-direction, the object's initial angle is 90 degrees (PI / 2 radians)

	Standard change in coordinate formulas:
		(delta) x = cos(angle) * distance
		(delta) y = sin(angle) * distance

	math.h uses radians.
	degree to radian calculation:
		radians = degree * PI / 180
*/
int main(){
	int numCases;
	int n,i,j;
	double degree, direction, dist;
	double x,y;

	scanf("%d", &numCases);
	for(i = 0; i < numCases; i++){
		scanf("%d", &n);
		x = 0;
		y = 0;
		direction = M_PI / 2;
		for(j = 0; j < n; j++){
			scanf("%lf %lf", &degree, &dist);
			direction += (degree * M_PI / 180);
			x += cos(direction) * dist;
			y += sin(direction) * dist;
		}
		printf("%lf %lf\n", x, y);
	}
}