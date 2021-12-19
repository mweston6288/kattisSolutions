#include <stdio.h>
#include <math.h>

int main(){
	int num;
	scanf("%d", &num);
	int i, input;
	int res =0;
	for(i=0; i<num;i++){
		scanf("%d", &input);
		res+= pow(input / 10, input % 10);
	}
	printf("%d\n", res);
}
