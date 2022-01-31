#include <stdio.h>
#include <math.h>
/*
	A rectangle has dimensions X x Y.
	The rectangle will be cut and folded into a lidless box of dimensions a X b x h
	volume = abh

	a = X - 2h
	b = Y - 2h
	h = (X-a) / 2 = (Y-b) / 2

	volume = abh = (X-2h)(Y-2h)h = XYh - 2h^2(X+Y) + 4h^3 = f(h)
	max volume can be found from finding local maxima
	f'(h) = 12h^2 - 4h(X+Y) + XY = 0
	
	Not easy to determine h from f'(h) so will use a binary search approach

	f(h) is a 3 degree polynomial with a positive leading coefficient so it will have a local max followed by a local min
	
	local maxima is guaranteed to be left of (x+y) / 6 (parabolic center of f'(h))so that will be the upper bound
	if the assumed value of h cause f'(h) > 0, the value is too low. Otherwise if f'(h) < 0, h is too high
*/

int main(){
	int numCases,x,y;
	int i,j;
	double res, min, max;
	scanf("%d", &numCases);
	for(i = 0; i < numCases;i++){
		scanf("%d %d", &x, &y);
		max = (x+y) / 6.0;
		min = 0;
		res = max / 2.0;
		// run 60 trials. res will likely be unchanging long before 60 runs
		for(j = 0; j < 60;j++){
			// the current value of res is too low
			if(12 * res * res - 4*res*(x+y) + x*y > 0){
				min = res;
			}
			// too high
			else {
				max = res;
			}
			res = (max + min) / 2.0;
		}
		printf("%.8lf\n", 4*pow(res,3) - 2*res*res*(x+y) + x*y*res);
	}
}