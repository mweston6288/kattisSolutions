#include <stdio.h>
#include <stdlib.h>

// given a range [l,d] and a value x, find the minimum and maximum numbers in the range whose digits sum to x

// solution logic: if a == b (mod 9), then sum(a) == sum(b) (mod 9)
// to reduce number of checks, I'll prime l and d so sum(l) and sum(d) == x (mod 9)
// Then I'll jump 9 spaces until I've got the number I want

// since the possible numbers passed in are in range [1,10000], I'm just going to get each digit and sum them
int sum(int n){
	int a,b,c,d,e;
	e = n % 10;
	d = n / 10 % 10;
	c = n / 100 % 10;
	b = n / 1000 % 10;
	a = n / 10000;
	return a+b+c+d+e;
}


void getMin(int l,int x){
	int suml = sum(l);
	int v = l;
	if (suml != x){
		l += (x % 9 - suml);
		suml = sum(l);
	}
	while (suml != x || v > l){
		l += 9;
		suml = sum(l);
	}
	printf("%d\n", l);
}

void getMax(int d, int x){
	int sumd = sum(d);
	int v = d;
	if (sumd != x){
		d += (x % 9 - sumd);
		sumd = sum(d);
	}
	while (sumd != x || v < d){
		d -= 9;
		sumd = sum(d);
	}
	printf("%d\n", d);
}
int main(){
	int l,d,x;
	scanf("%d %d %d", &l, &d, &x);
	getMin(l,x);
	getMax(d,x);
}