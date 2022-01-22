#include <stdio.h>
/*
	What's the maximum number of * on a RxS rectangle can be stored inside a KxK square
	The square must be entirely within the rectangle and * on the borders of the square do not count

	There's no point in checking along the first or last row/column since only the square border can touch them
*/
int main(){
	int r,s,k;
	int i,j,m,n, count;
	int max = 0;
	// store the top left corner of the square with max * in it
	int maxX, maxY;
	char win[100][101];
	scanf("%d %d %d\n", &r, &s, &k);
	for(i = 0; i < r;i++){
		scanf("%s\n", win[i]);
	}

	// trim some values so the loops don't have to recalculate them every time
	k -= 2;
	r -= k;
	s -= k;
	// for each point the internal square could be
	for(i = 1; i < r; i++){
		for(j = 1; j < s;j++){
			count = 0;
			// count all the '*' in the square
			for(m = 0; m < k;m++){
				for (n = 0; n < k; n++){
					if(win[i+m][j+n] == '*'){
						count++;
					}
				}
			}
			// save the square coordinate with the highest count
			if(count > max){
				max = count;
				maxX = i;
				maxY = j;
			}
		}
	}
	// draw the corners of the square
	win[maxX-1][maxY-1] = '+';
	win[maxX-1][maxY+k] = '+';
	win[maxX+k][maxY-1] = '+';
	win[maxX+k][maxY+k] = '+';
	// draw the sides of the square
	for(i = 0; i < k;i++){
		win[maxX-1][maxY+i] = '-';
		win[maxX+k][maxY+i] = '-';
		win[maxX+i][maxY-1] = '|';
		win[maxX+i][maxY+k] = '|';
	}
	// restore r to its former value so we can print everything
	r += k;
	printf("%d\n",max);
	for(i = 0; i < r;i++){
		printf("%s\n", win[i]);
	}
}