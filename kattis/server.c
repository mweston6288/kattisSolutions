#include <stdio.h>

int main(){
	int n, t, current = 0, res = 0, temp, i;
	scanf("%d %d", &n, &t);

	for(i = 0; i < n; i++){
		scanf("%d", &temp);
		if(current + temp <= t){
			current += temp;
			res++;
		}
		else{
			break;
		}
	}
	printf("%d\n", res);
}