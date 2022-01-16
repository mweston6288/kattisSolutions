#include <stdio.h>
#include <math.h>

/*
	A cirlce C of radius r is split in two pieces at point p. p ends up being the center of the shortest possible line
	from one endpoint of C to another (We'll call those endpoints A and B)

	If p is at (x,y) and C's center is (0,0), then p is located sqrt(x^2 + y^2) from the center (length d).
	The distance from the center O to A or B is r.
	We can make two right triangles ApO and BpO, ApO = BpO

	Angle pOA and pOB = cos^-1(d / r)

	The area of the circle's segment is (2*angle(poA)/360) * pi*r^2 - area(AOB)

	We know the height of POB (d). To find the base, use pythagorean theorem, b = sqrt(r^2 - d^2). Normally,
	you'd multiply this by 2 since it gives half the base, but we only need half for the area

	segment created at point p = (2*angle(poA)/360) * pi*r^2 - d*b
*/

int main(){
	double r,x,y;
	// areas of the two segments made
	double a1,a2;
	while(scanf("%lf %lf %lf", &r,&x,&y) == 3){
		// I don't need the original x-coordinate after this so Ill recycle it
		x = sqrt(x*x+y*y);
		if (x > r){
			printf("miss\n");
			continue;
		}
		// store the whole circle area
		a2 = M_PI*r*r;
		// initially use a1 to store the angle of the segment
		a1 = 2*acos(x/r);
		// get the area of the segment + isoceles triangle used to calculate it
		a1 = a2*(a1/(2*M_PI));
		// subtract out the triangle's area
		// calculated half of base * height (x)
		a1 -= sqrt(r*r - x*x)*x;

		// subtract the segment from the whole circle
		a2 -= a1;

		// print the bigger one first
		if (a1 > a2){
			printf("%lf %lf\n", a1,a2);
		}
		else{
			printf("%lf %lf\n", a2,a1);
		}
	}
}