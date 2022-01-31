#include <stdio.h>
/*
	Determine if babby with full mouth is counting right. Assume they don't choke.

	Any instance of mumble can be ignored as correct. The only time they count wrong is when a
	spoken number is definitely in the wrong place.

	since numbers and "mumble" can both be read in at any moment, just read them as a string and
	convert to int when needed.
*/
// convert a string representation of an int to an int
int toInt(char *s){
	int i, n = 0;
	for(i = 0; s[i] != '\0';i++){
		n = n*10 + s[i]-'0';
	}
	return n;
}
int main(){
	int n,i;
	char s[7];
	scanf("%d\n", &n);

	for(i = 1; i <= n;i++){
		scanf("%s", s);
		if(s[0] != 'm'){
			if (toInt(s) != i){
				printf("something is fishy\n");
				return 0;
			}
		}
	}
	printf("makes sense\n");
}