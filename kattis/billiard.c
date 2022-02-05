#include <stdio.h>
#include <math.h>
/*
	billiard board of dimensions a x b. Ball is in the exact center of the board

	ball is hit and returns to initial point after s seconds and bounces off the vertical sides m times 
	and horizontal n times

	Determine launching angle and initial velocity

	velocity = distance traveled / time

	each time the ball hits a vertical end, it has to travel length a before hitting another vertical end
	each time the ball hits a horizontal end, it has to travel length b before hitting another horizontal end
	total distance traveled therefore is sqrt((a*m)^2 + (b*n)^2)
	velocity = 	sqrt((a*m)^2 + (b*n)^2) / s

	After finding the total distance traveled, we can determine the launch angle by finding sin^-1(b*n / distance)
*/
int main(){
	int a,b,s,m,n;
	double dist, ang;
	scanf("%d %d %d %d %d", &a,&b, &s, &m, &n);

	do{
		dist = sqrt(pow(a*m, 2) + pow(b*n, 2));
		ang = asin(b*n / dist);
		// radians to degrees
		ang = ang*180 / M_PI;
		printf("%.2lf %.2lf\n", ang, dist / s);
		scanf("%d %d %d %d %d", &a,&b, &s, &m, &n);
	}while(s);
}