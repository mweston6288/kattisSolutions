#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Given the corner coordinates of a straight-edge polygon, calculate how much it needs to be 
	scaled down so that a curve-edged polygon of equal length can be drawn around it with radius r

	Get the total distance d by getting the sum of distances from each point
	The length of the curves of the curve-edged polygon sum to a circle of circumference c = pi*2*r
	The scale factor is equal to 1 - c/d

	If c > d, it's not possible to scale-down
*/

double getDist(int x1, int y1, int x2, int y2){
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
int main(){
	int numCases;
	int r, n;
	int (*coord)[2];
	int i,j;
	double d,c;
	scanf("%d", &numCases);
	for(i = 0; i < numCases; i++){
		scanf("%d %d", &r, &n);
		coord = malloc(sizeof(int[2]) * n);
		for(j = 0; j < n; j++){
			scanf("%d %d", &coord[j][0], &coord[j][1]);
		}
		d = getDist(coord[0][0], coord[0][1], coord[n-1][0], coord[n-1][1]);
		for(j = 1; j < n; j++){
			d += getDist(coord[j][0], coord[j][1], coord[j-1][0], coord[j-1][1]);
		}
		c = M_PI*2*r;
		if(c <= d){
			printf("%.6lf\n", 1 - c/d);
		}
		else{
			printf("Not possible\n");
		}
		free(coord);
	}
}