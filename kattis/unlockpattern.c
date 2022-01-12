#include <stdio.h>
#include <math.h>
/*
	Find the total distance traveled to reach each integer in a 3x3 grid in ascending order
	Traveling one cell vertically or hirizontanlly counts as 1 unit traveled
*/

int main(){
	// finder will store which cell each number is stored
	// finder[0] is junk
	int finder[10];
	int i,x1,y1,x2,y2;
	double res = 0;

	// read each number. In index x1, we store what loop that particular number was read
	for(i = 0; i < 9;i++){
		// x1 has greater importance later, but for now, I can just use it to read values
		scanf("%d", &x1);
		finder[x1] = i;
	}

	// priming the distance calculation. divide by 3 gets the x coordinate
	// mod by 3 gets the y coordinate
	x2 = finder[1] /3;
	y2 = finder[1] % 3;

	// get the distance from number i to number i-1
	for(i = 2; i <= 9;i++){
		x1 = x2;
		y1 = y2;
		x2 = finder[i] / 3;
		y2 = finder[i] % 3;
		// distance formula
		res += sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
	}

	printf("%lf\n", res);
}