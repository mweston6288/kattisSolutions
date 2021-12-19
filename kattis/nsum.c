#include <stdio.h>
// get the sum of a set of ints
int main(){
	int a,b, numInts;
	scanf("%d", &numInts);
	// get the first int
	scanf("%d", &a);
	// get each subsequent int and add them to a
	for(int i = 1; i < numInts;i++){
		scanf("%d", &b);
		a+=b;

	}
	printf("%d\n", a);
}