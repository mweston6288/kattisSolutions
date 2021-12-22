#include <stdio.h>
/*
 given a rectangle's original width, then number of rectangles it's been broken into
 and the length and width of each piece, determine the length of the original rectangle

 solution: add the area of each piece together and divide the sum by the given width

*/

int main(){
	int originalWidth;
	scanf("%d", &originalWidth);

	int numPieces;
	scanf("%d", &numPieces);
	int area = 0;
	int l,w;
	for(int i = 0; i < numPieces; i++){
		scanf("%d %d", &l, &w);
		area += (l*w);
	}
	printf("%d\n", area / originalWidth);
}