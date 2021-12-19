#include <stdio.h>

// harshad numbers a numbers where the sum of their digits can divide the number

// given an integer, return the smallest harshad number >= it

int isHarshad(int h){
	int sum = 0;
	int t = h;
	while (t > 0){
		sum +=(t % 10);
		t /=10;
	}
	return h % sum == 0 ? 1: 0;
}
int main(){
	int h;
	scanf("%d", &h);
	while (1){
		// there's no effective way to determine when the next harshad number is
		// aside for the biggest gap will be 9 numbers because of how 9 divisibility works
		if(isHarshad(h)){
			printf("%d\n", h);
			break;
		}
		h++;
	}
}