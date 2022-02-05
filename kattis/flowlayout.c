#include <stdio.h>
/*
	maxWidth - longest width a series of rectangles is allowed to stretch in one row
	w - width of a single rectangle
	h - height of a single rectangle
	finalWidth - maximum width of any row of rectangle created; updates when currentWidth + w > finalWidth
	finalHeight - distance from the bottom-most rectangle to the topmost rectangle; updates when currentHeight + h > finalWidth
	currentWidth - sum of the widths of every rectangle in the row; resets to 0 when currentWidth + w > maxWidth
	currentHeight - max height of the previous row; gets set to finalHeight when currentWidth + w > maxWidth
*/

int max (int a, int b){
	return a > b ? a : b;
}
int main(){
	int maxWidth, w, h, finalWidth, finalHeight, currentWidth, currentHeight;

	scanf("%d", &maxWidth);
	do {
		finalWidth = 0;
		finalHeight = 0;
		currentWidth = 0;
		currentHeight = 0;
		scanf("%d %d", &w, &h);
		do{
			// cannot fit in this row, move to new row
			if(w + currentWidth > maxWidth){
				// new row so height will definitely get updated
				currentHeight = finalHeight;
				finalHeight += h;
				// check if new rectangle is longer than the previous row
				currentWidth = w;
				finalWidth = max(finalWidth, currentWidth);
				
			}
			// can fit
			else{
				currentWidth += w;
				finalWidth = max(finalWidth, currentWidth);
				finalHeight = max(finalHeight, currentHeight + h);
			}

			scanf("%d %d", &w, &h);
		} while(w != -1);
		printf("%d x %d\n", finalWidth, finalHeight);
		scanf("%d", &maxWidth);

	} while(maxWidth);
}