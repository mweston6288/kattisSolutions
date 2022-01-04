#include <stdio.h>

int main(){
	int num;
	int prev=0, next=0,i,j;
	scanf("%d", &num);
	
	for(i = 0; i < num; i++){
		prev = next;
		scanf("%d", &next);
		for(j = prev + 1; j < next; j++){
			printf("%d\n", j);
		}
	}
	if(num == next){
		printf("good job\n");
	}
}