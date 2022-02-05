#include <stdio.h>
/*
	M groups are attempting to enter a building which can accomodate at-most n people
	Once one group would cause the building to be over capacity, all remaining groups must leave.
	Determine the number of groups that leave.
*/
int main(){
	int n, m, i, t, res = 0, count = 0;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++){
		scanf("%d", &t);
		// check if this group would be over capacity
		if(t + count > n){
			break;
		}
		// add them to the group and total count
		count += t;
		res++;
	}
	printf("%d\n", m - res);
}