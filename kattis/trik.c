#include <stdio.h>
#include <string.h>

// An object is placed in the leftmost cup (1), the cups are shuffled around.
// determine which cup has the object

/*
	A - Swap 1 and 2
	B - Swap 2 and 3
	C - Swap 1 and 3
*/

int main(){
	char seq[54];
	scanf("%s", seq);
	int len = strlen(seq);
	int active = 1;
	int i;

	for(i = 0; i < len; i++){
		// active is now 1
		if((seq[i] == 'A' && active == 2) || (seq[i] == 'C' && active == 3) || (seq[i] == 'B' && active == 1))
			active = 1;
		// active is now 2
		else if((seq[i] == 'A' && active == 1) || (seq[i] == 'B' && active == 3) || (seq[i] == 'C' && active == 2))
			active = 2;
		else
			active = 3;
	}
	printf("%d\n", active);
}