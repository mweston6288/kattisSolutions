#include <stdio.h>

/*
	If the hydra has 0 tails and an odd number of heads, it's unkillable

	Process when hydra has h heads and t tails:
		if h is odd:
			cut 1 tail n times until t == 2 mod 4, n = (6 - t%4) % 4 (Ensures the result is a positive int < 4)
			cut 2 tails at a time causing h to be even and t = 0, (t+n)/2 actions taken
			cut 2 heads at a time until h = 0, h/2 + (t+n)/4 actions taken; (t+n)/4 is the number of heads created after cutting off the tails
		If h is even:
			cut 1 tail n times until t == 0 mod 4, n = (4 - t%4) % 4 (Ensures the result is a positive int < 4)
			cut 2 tails at a time until t = 0, (t+n)/2 actions taken
			cut 2 heads at a time until h = 0, h/2 + (t+n)/4 actions taken

		End result:
			Calculate n
			total number of actions is n + (t+n)/2 + h/2 + (t+n)/4
			= n + h/2 + (t+n)*3/4
*/
int main(){
	int h,t,res;
	scanf("%d %d", &h, &t);
	do {
		res = 0;
		if (h & 1){
			if(t == 0){
				res = -1;
			}
			else{
				res = (6 - t % 4) % 4;
				t += res;
				// +1 to compensate for integer division.
				res += t*3/4 + h/2 + 1;
			}
		}
		else{
			res = (4 - t % 4) % 4;
			t += res;
			res += t*3/4 + h/2;	
		}
		printf("%d\n", res);
		scanf("%d %d", &h, &t);
	} while(h || t);

}