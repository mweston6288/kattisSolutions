#include <stdio.h>
/*
	Determine how many letters in a sequence are the same as the previous letter
*/
int main(){
	int num, res = 0;
	char prev,next;
	scanf("%d\n%c\n", &num, &next);

	for (int i = 1; i < num;i++){
		prev = next;
		scanf("%c\n", &next);
		if (prev == next){
			res++;
		}
	}
	printf("%d\n", res);
}