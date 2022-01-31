#include <stdio.h>
/*
	Determine if two lights blinking at regular intervals will blink at the same time within s seconds

	Solution: Get the lcm of p and q
	lcm(p,q) = p*q / gcd(p,q)
*/
int getgcd(int a,int b){
	int r;
	do{
		r = a % b;
		a = b;
		b = r;
	} while(r != 0);
	return a;
}

int main(){
	int p,q,s;
	scanf("%d %d %d", &p, &q, &s);

	if(p*q / getgcd(p,q) <= s){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
}