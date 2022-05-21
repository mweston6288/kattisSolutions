#include <stdio.h>
/*
	Given n bank transactions (positive are deposits, negative are withdrawals), determine
	the minimum initial balance needed to ensure there are no overdraft fees.

	Solution: Assume an initial balance of 0. Run each transaction and calculate the balance
		afterward. If the balance is negative, add the necessary amount to the initial balance
		to make it 0.
*/
int main(){
	int n, res = 0, balance = 0, m, i;
	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d", &m);
		// add the transaction
		balance += m;
		// check if we have an overdraft
		if (balance < 0){
			res += -balance;
			balance = 0;
		}
	}
	printf("%d\n", res);
}