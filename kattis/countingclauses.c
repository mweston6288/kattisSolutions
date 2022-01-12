#include <stdio.h>
/*
	The problem is super wordy, but all it wants is whether the first number is 8 or greater
*/
int main(){
	int n;
	scanf("%d", &n);
	printf("%ssatisfactory\n", n >= 8 ? "" : "un");
}