#include <stdio.h>
/*
	For an integer N, determine the smallest integer M such that the sum of all digits of N
	is the same as the sum of all digits of N*M

	M must be greater than 10.
*/
// gets the sum of digits
int getSum(int n){
	int res = 0;
	while(n > 0){
		res += (n % 10);
		n /= 10;
	}
	return res;
}

int main(){
	int n, sumN, m, sumM;
	scanf("%d", &n);

	while (n != 0){
		sumN = getSum(n);
		// N*100 is guaranteed to work so we'll stop the loop there
		for(m = 11; m <= 100; m++){
			sumM = getSum(n*m);
			if(sumN == sumM){
				printf("%d\n", m);
				break;
			}
		}
		scanf("%d", &n);
	}
}