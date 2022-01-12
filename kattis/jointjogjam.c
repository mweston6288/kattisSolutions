#include <stdio.h>
#include <math.h>

/*
	Two people are running in straight lines. They run at constant speeds (not necessarily the same speed to each other)
	and they start and end at the same time.

	The furthest they will ever be from each other is either at their start or end points
	so print the greater distance of those two points
*/

int main(){
	int x1init, y1init, x2init, y2init, x1fin, y1fin, x2fin, y2fin;

	double distinit, distfin;

	scanf("%d %d %d %d %d %d %d %d", &x1init, &y1init, &x2init, &y2init, &x1fin, &y1fin, &x2fin, &y2fin);

	distinit = sqrt(pow(x1init - x2init, 2) + pow(y1init - y2init, 2));
	distfin = sqrt(pow(x1fin - x2fin, 2) + pow(y1fin - y2fin, 2));

	printf("%.9lf\n", distinit > distfin ? distinit : distfin);

}