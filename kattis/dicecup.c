#include <stdio.h>
// idea: if two equal dice are rolled, the most likely value to occur
// is the greatest value of 1 die + 1
// If the dice have different max values, and max(m) < max(n), all values in range [m+1, n+1]
// are equally and most likely
int main(){
	int m,n, i;
	scanf("%d %d", &m, &n);
	// make sure m is always less than n
	if(m > n){
		i = m;
		m = n;
		n = i;
	}
	n++;
	for(i = m+1; i <= n; i++){
		printf("%d\n", i);
	}
}