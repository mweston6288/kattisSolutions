#include <stdio.h>

int main(){
	int p,q;
	scanf("%d %d", &p, &q);
	if (p <= q){
		printf("Dr. Chaz will have %d piece%s of chicken left over!\n", q-p, q-p == 1 ? "" : "s");
	}
	else{
		printf("Dr. Chaz needs %d more piece%s of chicken!\n", p-q, p-q == 1 ? "" : "s");
	}
}