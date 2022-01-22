#include <stdio.h>
/*
	We're given the amount of three juices and the proportion of each juice to make a cocktail

	The limiting factor on how much cocktail can be made is whichever juice gets used up first

	by dividing each juice amount by the proportion needed I can get the units of cocktail made
	if that juice was the one used up first. The smallest number determines which juice will get used first

	Once I know the juice that gets used up first, I can determine how much juice has to be used for every
	1 unit of the limiting juice

	Finally, multiply that amount by the amount of limiting juice available to find how much of the other
	juices are used

*/
int main(){
	// amounts of juice
	double a,b,c;
	// proportions
	double i,j,k;
	double num;
	scanf("%lf %lf %lf %lf %lf %lf", &a,&b,&c,&i,&j,&k);

	// how much cocktail could be made if a,b,and c respectively were fully consumed
	double t1,t2,t3;
	t1 = a/i;
	t2 = b/j;
	t3 = c/k;

	// determine which proportion is the true limiting factor
	// and set t1,t2,t3 to how much juice to use to make a cocktail
	// set num to total cocktails that can be made
	// juice a is consumed first
	if(t1 < t2 && t1 < t3){
		t1 = 1;
		t2 = j/i;
		t3 = k/i;
		num = a;
	}
	// juice b is consumed first
	else if(t2 < t3){
		t1 = i/j;
		t2 = 1;
		t3 = k/j;
		num = b;
	}
	// juice c is consumed first
	else{
		t1 = i/k;
		t2 = j/k;
		t3 = 1;
		num = c;
	}
	printf("%lf %lf %lf\n", a - t1*num,b - t2*num, c - t3*num);
}