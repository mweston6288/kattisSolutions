#include <stdio.h>

/*
	Determine the number of passwords that can be made where
	each digit matches the digit of two given passwords
*/
int main(){
	char x[5], y[5];
	int res = 1;
	scanf("%s %s", x, y);
	for(int i = 0; i < 4; i++){
		if(x[i] != y[i]){
			res <<= 1;
		}
	}
	printf("%d\n", res);
}