#include <stdio.h>
#include <string.h>
#include <math.h>
/*
	To determine the zoom level of the map from the quadkey, simply get the length of the quadkey.

	the coordinate can be determined by starting at (0,0) and either staying at that spot 
	or jumping to the halfway point from where you currently are to (2^n, 2^n) where n is the length of the quadkey
*/

int main(){
	char s[32];
	scanf("%s", s);
	int len = strlen(s);
	int x=0,y=0;

	for(int i = 0; i < len; i++){
		// if the value is 1 or 3, then the quadkey refers to the right side of the quadrant
		if(s[i] == '1' || s[i] == '3'){
			x += (int)pow(2, len-i-1);
		}
		// if the value is 2 or 3, the quadkey is referring to the lower half of the quadrant
		if(s[i] == '2' || s[i] == '3'){
			y += (int)pow(2, len-i-1);
		}
	}
	printf("%d %d %d\n", len, x,y);
}