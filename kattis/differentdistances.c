#include <stdio.h>
#include <math.h>
/*
	Given two coordinates and a power, determine the p-norm distance between them

	Due to C's abs() function only working with ints, this solution has to manually convert
	the values to absolute
*/

// convert a double to absolute value
double absD(double d){
	if (d < 0){
		return d * -1.0;
	}
	return d;
}
int main(){
	long double x1,x2,y1,y2,p;
	long double distx,disty;
	while (1){
		if(scanf("%Lf %Lf %Lf %Lf %Lf", &x1, &y1,&x2,&y2,&p) == 1){
			break;
		}
		distx = pow(absD(x1-x2), p);
		disty = pow(absD(y1-y2), p);
		
		printf("%lf\n", pow( distx+disty, (1.0/p)));

	}
}