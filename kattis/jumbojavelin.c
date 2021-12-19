#include <stdio.h>

int main(){
	int numJ, i,next, res=0;
	scanf("%d", &numJ);
	for(i = 0; i < numJ; i++){
		scanf("%d", &next);
		res+=next;
	}
	// just gonna subtract the excess all at once
	printf("%d\n", res - numJ + 1);
}