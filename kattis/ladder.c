#include <stdio.h>
#include <math.h>
// Given a right triangle's height and opposite angle, determine the hypotenuse rounded up
// sin(x) = opposite / hypotenuse  -> hypotenuse = opposite / sin(x)

// rounds a number up if needed
int roundup(double d){
	int i = (int)d;
	if (i < d){
		return i + 1;
	}
	return i;
}
int main(){
	int opp;
	double x;
	scanf("%d %lf", &opp, &x);
	// convert to radians
	x = x * M_PI / 180;
	printf("%d\n", roundup(opp / sin(x)));

}