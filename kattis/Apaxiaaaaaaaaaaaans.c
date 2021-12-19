#include <stdio.h>

int main(){
	char c,d;
	scanf("%c", &c);
	printf("%c", c);
	while (c != '\n'){
		scanf("%c", &d);
		if (c == d){
			continue;
		}
		c = d;
		printf("%c", c);
	}
}