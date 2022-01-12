#include <stdio.h>
#include <math.h>
/*
	Area of regular n-gon with side length b:
		n-gon can be divided into n isoceles triangles with base b and opposite angle 360 / n
		other angles = (180 - (360/n)) / 2 = 90 - 180/n
		area of triangle = bh/2
		h = b/2 * tan(90 - 180/n)
		a = b * b/2 * tan(90 - 180/n) / 2 = b^2 * tan(90-180/n) / 4

		Since math.h tan() uses radians, 90 - 180/n needs to be multiplied by pi/180
		which is pi/2 - pi/n

		area of all n triangles is n * b^2 * tan(pi/2 - pi/n) / 4
		

		With the expansions, there's a side and corner expansion.

		Side expansion creates n rectangles of lengths b and dg where d is the expansion distance and 
		g is the number of times the polygon expands
		So total side expansion is n*b*d*g

		All the n corners created form a single cirdle with radius d*g. So the area is (d*g)^2 * pi

		So the final answer to area of a regular n-gon of side length b expanded g times by length d is
		n * b^2 * tan(pi/2 - pi/n) / 4 + n*b*d*g + (d*g)^2 * pi


*/
int main(){
	int numCases;
	scanf("%d", &numCases);
	int n,b,d,g;
	double a;
	for(int i = 0; i < numCases;i++){
		scanf("%d %d %d %d", &n, &b, &d, &g);
		// area of original n-gon
		a = .25 * n * b * b * tan(M_PI / 2 - M_PI / n);
		// area of side expansions
		a += n*b*d*g;
		// area of corner expansions
		a += d*d*g*g*M_PI;

		printf("%.7lf\n", a);
	}


}