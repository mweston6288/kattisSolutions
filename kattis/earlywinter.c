#include <stdio.h>
/*
	Find the first number in a set <= m.
*/
int main(){
	int m,d,n,i;
	scanf("%d %d", &m, &d);
	for(i = 0; i < m;i++){
		scanf("%d", &n);
		if(n <= d){
			// thankfully, I don't have to correct for plural
			printf("It hadn't snowed this early in %d years!\n", i);
			return 0;
		}
	}
	// nothing found
	printf("It had never snowed this early!\n");
}