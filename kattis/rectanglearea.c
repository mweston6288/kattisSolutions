#include <stdio.h>
/*
	Get the area of a rectangle given two opposite corner coordinates.

	Solution: Get the difference of the corners' x and y values and multiply them. Then get the absolute value
*/
// convert a double to absolute value
double absD(double d){
	if (d < 0){
		return d * -1.0;
	}
	return d;
}
int main(){
	double x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

	printf("%lf\n", absD((x1 - x2) * (y1 - y2)));

}