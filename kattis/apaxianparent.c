#include <stdio.h>
#include <string.h>
/*
	Given two strings, s1 and s2, append them using the following rules:
		If s1 ends in a vowel, replace the vowel with 'e' and print s1+'x'+s2
		If s1 ends with "ex", print s1+s2
		Otherwise, print s1+"ex"+s2
*/
int main(){
	char name[11], parent[11];
	scanf("%s %s", name, parent);
	// gonna do a minus 1 to reduce math work later
	int len = strlen(name) -1;
	// check if it ends with "ex" already
	if(!strcmp(&name[len-1], "ex")){
		printf("%s%s\n", name, parent);
	}
	// check if it ends with a vowel
	// here's why I had len - 1 earlier
	else if(name[len]=='a'||name[len]=='e'||name[len]=='i'||name[len]=='o'||name[len]=='u'){
		name[len] = 'e';
		printf("%sx%s\n",name,parent);
	}
	else{
		printf("%sex%s\n",name,parent);
	}
}