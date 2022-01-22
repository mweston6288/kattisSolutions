#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a,b,c;
	scanf("%d %d %d", &a,&b,&c);

	// I can't believe I'd ever get the chance to use stooge sort legitimately
	if (a>b){
		swap(&a,&b);
	}
	if (b>c){
		swap(&b,&c);
	}
	if (a>b){
		swap(&a,&b);
	}
	// if equal, no gaps; print next number in sequence
	if(b - a == c - b){
		printf("%d\n", c+c-b);
	}
	// if true, gap between b and c; use a to determine the number
	else if(b - a < c - b){
		printf("%d\n", b+b-a);
	}
	// if true, gap between a and b; use c to determine the gap
	else{
		printf("%d\n", a+c-b);
	}
}