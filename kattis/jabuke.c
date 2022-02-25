#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
	Given a triangle's coordinates, determine its area and how many of the next several coordinates
	are in the triangle.

	If a point T is in triangle ABC, it will split the triangle into three triangles: ABT, ATC, TBC
	If the area of those three triangles is equal to the area of ABC, T is in the triangle
*/

int main(){
	int xa,ya,xb,yb,xc,yc;
	int n, xt,yt, res = 0;
	double area, a1,a2,a3;
	scanf("%d %d %d %d %d %d", &xa,&ya,&xb,&yb,&xc,&yc);
	// get area of ABC
	area = abs(xa*(yb - yc) + xb*(yc-ya) + xc*(ya-yb)) / 2.0;
	printf("%.1lf\n", area);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &xt, &yt);
		// area of ABT
		a1 = abs(xa*(yb - yt) + xb*(yt-ya) + xt*(ya-yb)) / 2.0;
		// area of ATC
		a2 = abs(xa*(yt - yc) + xt*(yc-ya) + xc*(ya-yt)) / 2.0;
		// area of TBC
		a3 = abs(xt*(yb - yc) + xb*(yc-yt) + xc*(yt-yb)) / 2.0;

		res += area == (a1+a2+a3);
	}
	printf("%d\n", res);
}