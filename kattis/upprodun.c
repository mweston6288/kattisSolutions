#include <stdio.h>
/*
	Print m asterisks across n lines as evenly as possible
*/
int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	// div tells us how many stars will be in each row
	// mod tells us how many rows will have an extra star
	int div,mod;
	div = m / n;
	mod = m % n;
	int i, j;
	// print all the rows with an extra *
	for(i = 0; i < mod; i++){
		// went with this structure so I wouldn't have to modify div
		for(j = div+1; j > 0; j--){
			printf("*");
		}
		printf("\n");
	}
	// print the lines withut excess *
	for(i = n-mod; i > 0; i--){
		for(j = div; j > 0; j--){
			printf("*");
		}
		printf("\n");
	}
}