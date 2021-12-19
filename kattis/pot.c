#include <stdio.h>
#include <math.h>

// given a set of integers, rewrite them so the last digit is an exponent, then add them up

int main(){
	int num;
	scanf("%d", &num);
	int i, input;
	int res =0;
	for(i=0; i<num;i++){
		scanf("%d", &input);
		// splits the int into the base and exponent
		res+= pow(input / 10, input % 10);
	}
	printf("%d\n", res);
}
