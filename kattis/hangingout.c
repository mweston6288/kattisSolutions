#include <stdio.h>
/*
	Determine how many times a group of people were not allowed to enter a room due to exceeding capacity
*/
int main(){
	int maxCap, numEv, i, n, curr=0,res=0;
	char s[6];
	scanf("%d %d\n", &maxCap, &numEv);
	for(i = 0; i <numEv;i++){
		scanf("%s %d\n", s, &n);
		// since the event types are "enter" and "leave", I only need to check the first letter
		if(s[0] == 'e'){
			// too many people tried to enter
			if (n+curr > maxCap){
				res++;
			}
			// people could enter
			else{
				curr += n;
			}
		}
		else{
			curr -= n;
		}
	}
	printf("%d\n", res);
}