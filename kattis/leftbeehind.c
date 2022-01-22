#include <stdio.h>

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	
	while (m || n){
		if (m+n == 13){
			printf("Never speak again.\n");
		}
		else if( m > n){
			printf("To the convention.\n");
		}
		else if(m < n){
			printf("Left beehind.\n");
		}
		else{
			printf("Undecided.\n");
		}
		scanf("%d %d", &m, &n);
	}
}