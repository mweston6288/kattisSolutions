#include <stdio.h>

int main(){
	int i,res = 0;
	scanf("%d", &i);
	while (i > 0){
		res <<= 1;
		res += i&1;
		i >>= 1;
	}
	printf("%d\n", res);
}