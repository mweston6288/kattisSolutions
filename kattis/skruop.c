#include <stdio.h>
/*
	The volume of a speaker is set to 7. It has a range 0 - 10
	When told to raise the volume ("skru op!"), raise the volume by 1 if possible
	When told to lower the volume ("skru ned!"), lower the volume by 1 if possible

	If told to raise volume while at max or lower volume while at min, ignore the command

	The inputs are only "skru op!" and "skru ned!". Index 5 of each command is guaranteed to be different
	so I check the value at that index rather than use strcmp.

*/
int main(){
	int vol = 7;
	char com[11];
	int n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		fgets(com, 11, stdin);
		// Told to raise volume and can raise volume
		if(com[5] == 'o' && vol < 10){
			vol++;
		}
		// Told to lower volume and can lower volume
		else if(com[5] == 'n' && vol > 0){
			vol--;
		}
	}
	printf("%d\n", vol);
}