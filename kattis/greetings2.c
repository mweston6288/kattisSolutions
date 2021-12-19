#include <stdio.h>
#include <string.h>

int main(){
	char greeting[1010];
	char response[2020];
	scanf("%s", greeting);
	int len = strlen(greeting);
	strcpy(response, greeting);
	response[len - 1]= '\0';
	strcat(response, &greeting[1]);
	printf("%s\n", response);
}