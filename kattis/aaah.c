#include <stdio.h>
#include <string.h>

int main(){
	char a[1001];
	char b[1001];
	scanf("%s\n%s", a,b);
	int lenA, lenB;
	lenA = strlen(a);
	lenB = strlen(b);
	if(lenA >= lenB){
		printf("go\n");
	}
	else{
		printf("no\n");
	}
}