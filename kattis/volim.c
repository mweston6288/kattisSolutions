#include <stdio.h>
/*
	Determine who was holding the item after 3 minutes 30 seconds (210 seconds)

	Once t > 210, we can just porint whoever was holding the item and end the program
*/
#define CONTESTANTS 8
#define TIME 210

int main(){
	int init, numTurns,t=0,i,j;
	char c;
	scanf("%d %d", &init, &numTurns);
	for(i = 0; i < numTurns;i++){
		scanf("%d %c", &j, &c);
		t += j;
		if (t > TIME){
			printf("%d\n", init);
			return 0;
		}
		// The item got passed only when c == 'T'
		if (c == 'T'){
			// Since the numbers are 1 to 8, this order ensures init is in that range
			init = init % CONTESTANTS + 1;
		}
	}
}