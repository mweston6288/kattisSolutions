#include <stdio.h>
// print 1 if a 7-digit number starts with 555, otherwise print 0
int main(){
	int num;
	scanf("%d", &num);
	printf("%d\n", num / 10000 == 555 ? 1 : 0);
}