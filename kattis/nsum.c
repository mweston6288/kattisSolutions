#include <stdio.h>

int main(){
	int a,b, numInts;
	scanf("%d", &numInts);
	scanf("%d %d", &a, &b);
	a += b;
	for(int i = 2; i < numInts;i++){
		scanf("%d", &b);
		a+=b;

	}
	printf("%d\n", a);
}