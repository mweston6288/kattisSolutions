#include <stdio.h>
/*
	A robot is in a box and can move up,down, left, or right
	It will keep moving even if it hits a wall.
	Determine its exact location in the box and where the robot would be if there were no walls
*/

int getMin(int a, int b){
	return a < b ? a : b;
}
int getMax(int a, int b){
	return a > b ? a : b;
}

int main(){
	// length and width
	int l,w;
	int numCommands;
	// actual coordinates and assumed coordinates
	int x1,y1,x2,y2;
	// reads in the direction
	char c;
	// incrementor and step counter
	int i,n;
	while(1){
		scanf("%d %d", &w, &l);
		// if l and w are 0 we're done. Valid inputs are guaranteed to be greter than 1
		if(!l){
			break;
		}
		l--;
		w--;
		x1 = y1 = x2 = y2 = 0;
		scanf("%d\n", &numCommands);
		for(i = 0; i < numCommands;i++){
			scanf("%c %d\n", &c, &n);
			// determine where the robot is and where it thinks it is
			// up
			if(c=='u'){
				y2+=n;
				y1 = getMin(l, y1+n);
			}
			// down
			else if(c=='d'){
				y2 -= n;
				y1 = getMax(0, y1-n);				
			}
			// right
			else if(c=='r'){
				x2 += n;
				x1 = getMin(w, x1+n);				
			}
			// left
			else if(c=='l'){
				x2 -= n;
				x1 = getMax(0, x1-n);				
			}
		}
		printf("Robot thinks %d %d\nActually at %d %d\n\n", x2,y2,x1,y1);
	}
}