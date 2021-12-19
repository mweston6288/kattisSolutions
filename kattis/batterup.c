#include <stdio.h>

int main(){
	int bases;
	double sum=0;
	int t, i, n;
	
	scanf("%d", &bases);
	n = bases;
	for(i = 0; i < n; i++){
		scanf("%d", &t);
		if (t == -1){
			bases--;
			continue;
		}
		sum += t;
	}
	printf("%lf\n", sum / bases);
}