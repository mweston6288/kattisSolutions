#include <stdio.h>
// swap the values of a two digit integer
int main(){
	int i;
	scanf("%d", &i);
	int j = i % 10; // get one's place value
	// use math to swap
	printf("%d\n", i / 10 + j* 10);
}