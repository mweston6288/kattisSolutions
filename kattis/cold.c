#include <stdio.h>

int main(){
	int num,n,res=0, i;
	scanf("%d", &num);
	for(i =0; i<num;i++){
		scanf("%d", &n);
		if (n < 0){
			res++;
		}
	}
	printf("%d\n", res);
}