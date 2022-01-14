#include <stdio.h>

/*
	If a-b=c, then a=b-c
	If a/b=c, then a=b*c
	Therefore, two equations are redundent and can be skipped
*/
int main(){
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);

	// This let's me split the checks slightly so fewer overall jumps
	if (a > b && a > c){
		if(a - b == c){
			printf("%d-%d=%d", a,b,c);
		}
		else{
			printf("%d/%d=%d", a,b,c);
		}
	}
	else{
		if(a + b == c){
			printf("%d+%d=%d", a,b,c);
		}
		else if(a * b == c){
			printf("%d*%d=%d", a,b,c);
		}
		else if(b - c == a){
			printf("%d=%d-%d", a,b,c);
		}
		else{
			printf("%d=%d/%d", a,b,c);
		}
	}

}