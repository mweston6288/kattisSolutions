#include <stdio.h>

// given an int n, count to n and then print "Abracadabra"

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		printf("%d Abracadabra\n", i);
	}
}