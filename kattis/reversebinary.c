#include <stdio.h>

// given an integer, determine what integer is created if you convert to binary and invert the order of bits

int main(){
	int i,res = 0;
	scanf("%d", &i);
	// just gonna shift each bit one-by-one from i to res
	while (i > 0){
		res <<= 1;
		res += i & 1; //bitwise AND tells me what is in the least significant bit
 		i >>= 1;
	}
	printf("%d\n", res);
}