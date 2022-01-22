#include <stdio.h>
/*
	The game ultimately boils down to if there's an equal number of black and white stones
	If there are, it's possible to perform the actions needed
*/
int main(){
	int w=0,b=0;
	char c;
	while (scanf("%c", &c) == 1){
		if(c == 'W'){
			w++;
		}
		else if (c == 'B'){
			b++;
		}
	}
	printf("%d\n", w == b);
}