#include <stdio.h>
#include <math.h>

/*
	Given the length of the four sides of a quadrilateral, determine the maximum possible area

	The formula for max area is K = sqrt((s-a)(s-b)(s-c)(s-d)) where s is the perimeter / 2
	and a,b,c, and d are the sides of the quadrilateral
*/

int main(){
	double a,b,c,d;
	double s;

	scanf("%lf %lf %lf %lf", &a, &b,&c, &d);
	s = (a+b+c+d) / 2;
	printf("%lf\n", sqrt((s-a)*(s-b)*(s-c)*(s-d)));
}