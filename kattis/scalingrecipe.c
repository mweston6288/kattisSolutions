#include <stdio.h>
/*
	Given a recipe creates x servings, determine the amount of the n ingredients needed to make y serivngs instead

	The scale factor can be found using y/x. Then multiply each ingredient by the scale
*/

int main(){
	int n, x, y, i, a;
	double scale;
	scanf("%d %d %d", &n, &x, &y);
	scale = 1.0 * y / x;
	for(i = 0; i < n; i++){
		scanf("%d", &a);
		printf("%.0lf\n", (a * scale));
	}
}