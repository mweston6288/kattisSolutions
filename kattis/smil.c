#include <stdio.h>
#include <string.h>
int main(){
	int i;
	char c[2050];
	fgets(c, 2049, stdin);
	int len = strlen(c);
	for(i = 0; i < len; i++){
		if(c[i] == ':' || c[i] == ';'){
			if(c[i+1] == '-' && c[i+2] == ')'){
				printf("%d\n", i);
				i+=2;
				continue;
			}
			if(c[i+1] == ')'){
				printf("%d\n", i);
				i++;
			}
		}
	}
}