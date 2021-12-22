#include <stdio.h>
#include <math.h>

// mile is based on distance traveled by roman soldiers after 1,000 paces.
// estimated Roman mile was 4854 feet
// given a distance in modern miles, determine how many paces a Roman soldier would take
// round to nearest whole number

int main(){
	double d;
	scanf("%lf", &d);
	printf("%d\n", (int)round(1000*(d*5280/4854)));
}