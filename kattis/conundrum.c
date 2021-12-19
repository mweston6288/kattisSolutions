#include <stdio.h>
#include <string.h>

int main(){
	char message[303];
	scanf("%s", message);
	int i, res = 0, len = strlen(message);
	for(i = 0; i< len; i +=3){
		if (message[i] != 'P')
			res++;
		if (message[i+1] != 'E')
			res++;
		if (message[i+2] != 'R')
			res++;			
	}
	printf("%d\n", res);
}