#include <stdio.h>

int main(){
	int i;
	scanf("%d", &i);
	int j = i % 10;
	printf("%d\n", i / 10 + j* 10);
}