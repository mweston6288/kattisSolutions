#include <stdio.h>
#include <string.h>
int main(){
	char names[100];
	scanf("%s", names);
	
	int len = strlen(names);
	printf("%c", names[0]);
	int i;
	for(i = 0; i < len; i++){
		if (names[i] == '-'){
			printf("%c", names[++i]);
		}
	}
	printf("\n");
}