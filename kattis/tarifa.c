#include <stdio.h>

int main(){
	int remMB;
	int months, i, x;
	scanf("%d %d", &remMB, &months);

	remMB = remMB * (months + 1);
	for (i = 0; i < months; i++){
		scanf("%d", &x);
		remMB -= x;
	}
	printf("%d\n", remMB);
}