#include <stdio.h>

/*
	Given a set of numbers, determine if a specific number is in that set
*/

// a helper function that handles checking the set
int keep(int p){
	int m, i, num, res = 0;
	// get number of elements in the set
	scanf("%d", &m);
	// check each item
	for(i = 0; i < m;i++){
		scanf("%d", &num);
		// if true, p is in the set
		// we don't need to check the others, but we do need to consume each int
		if(num == p){
			res++;
			for(++i;i<m;i++){
				scanf("%d", &num);
			}
			break;
		}
	}
	return res;
}

int main(){
	/*
		n = number of unique numbers; useless for this solution
		p = number to look for in each set
		s = number of sets to check
	*/
	int n,p,s;
	scanf("%d %d %d", &n,&p,&s);
	int i;
	for(i = 0; i < s;i++){
		if(keep(p)){
			printf("KEEP\n");
		}
		else
			printf("REMOVE\n");
	}
}