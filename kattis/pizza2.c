#include <stdio.h>
#include <math.h>
/*
	get percentage of area of inner circle to outer circle when given the total radius r and radius of the outer ring c

	inner circle area = (r-c)^2*pi
					  = (r-c)^2 *pi

	ratio = (r-c)^2 *pi / (r^2*pi)
		  = (r-c)^2 / r^2
*/
int main(){
	double r,c;
	scanf("%lf %lf", &r, &c);
	printf("%lf\n", (r-c)*(r-c) / (r*r) * 100);
}