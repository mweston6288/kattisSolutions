#include <stdio.h>
/*
	Take an improper raction and print it as a mixed fraction
*/
int main(){
	int num, den;

	while(1){
		scanf("%d %d", &num, &den);
		if(!den){
			break;
		}
		printf("%d %d / %d\n", num / den, num % den, den);
	}
}