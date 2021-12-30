#include <stdio.h>
#include <math.h>
/*
	Given a cylinder's diameter, which is equal to its height, find the diameter
	of a cylinder with the same proportional dimensions (diameter equals height)
	after a certain volume V of the original cylinder has been carved out, leaving two
	equal truncated cones and the internal cylinder.

	Volume of cylinder: pi*r^2*h
	Since d = h, the volume of the original cylinder is pi*(D/2)^2*D = pi*D^3/4
	The volume of the smaller cylinder with diameter d is therefore pi*d^3/4

	Volume of cone: pi*r^2*h / 3
	To determine the volume of the truncated cones, we'll need to determine the volume of a perfect 
	cone and subtract out the top part. Since two cones whould get made, h = D/2
	pi*(D/2)^2*(D/2) / 3 = pi*D^3 / 24

	The part of the cones to subtract has a height = d/2, and a radius = d/2
	truncated cone formula: pi*D^3 / 24 - pi*(d/2)^2*(d/2) / 3 = pi*D^3 / 24 - pi*d^3 / 24

	We have two truncated cones and the inner cylinder 
	so final volume = pi*D^3 / 12 - pi*d^3 / 12 + pi*d^3/4
	= pi*D^3 / 12 + 2pi*d^3 / 12
	= pi*(D^3+2d^3) / 12


	Therefore,
	pi*D^3 / 4 - V = pi*(D^3+2d^3) / 12
	3*pi*D^3 - 12V = pi*(D^3+2d^3)
	3*D^3 - 12V/pi = D^3 + 2d^3
	2*D^3 - 12V/pi = 2d^3
	D^3 - 6V/pi = d^3

	d = (D^3 - 6V/pi)^(1/3)




*/

int main(){
	double D,V;
	scanf("%lf %lf", &D,&V);
	while(D && V){
		printf("%lf\n", pow(pow(D,3) - 6*V/M_PI, 1.0/3));
		scanf("%lf %lf", &D,&V);
	}

}