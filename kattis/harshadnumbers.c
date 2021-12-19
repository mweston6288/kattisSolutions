#include <stdio.h>



int isHashad(int h){
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
		if(isHashad(h)){
			printf("%d\n", h);
			break;
		}
		h++;
	}
}