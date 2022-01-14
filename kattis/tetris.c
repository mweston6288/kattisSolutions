#include <stdio.h>
#include <stdlib.h>
/*
	Given a tetris fields with c columns and each column having a certain height, determine how many ways 
	to place each tetris piece such that there are no gaps beneath them

	1 - line piece:
		[]  - Can be placed vertically on any column
		[]
		[]
		[]

		[][][][] - Can be placed horizontally anywhere there are four columns of equal height
	2 - square piece:
		[][] - Can be placed anywhere there are two columns of equal height
		[][] 
	3 - squiggly piece:
		  [][] 	- Can be placed when two columns have equal height and next column has one extra height
		[][]

		[]   - Can be placed when left cloumn has one height more than right column
		[][]
		  []
	4 - reverse squiggly:
		[][]    - opposite conditions of squiggly
		  [][]

		  []
		[][]
		[]  
	5 - t block:
		  []
		[][][]  - can be placed on three columns of equal height

		[][][]
		  []    - can be placed on three columns where the middle column is one height shorter
		
		  []
		[][] -can be placed where left column is 1 height greater than right
		  []

		[]   - can be placed where right column is one height greater than left
		[][]
		[]
	6 - L block:
		[]  - can be placed where two columns have equal height
		[]
		[][]
	
		    [] -can be plaed where three columns have equal height
		[][][]

		[][] - can be placed where left column is two height greater than right
		  []
		  []

		[][][] - can be plaed where leftmost block is 1 less and middle and right are equal
		[]
	
	7 - reverse L block:
		  [] - can be placed where two columns have equal height
		  []
		[][]
		
		[]     -can be plaed where three columns have equal height
		[][][]

		[][] - can be placed where right column is two height greater than right
		[]
		[]

		[][][] - can be plaed where rightmost block is 1 less and middle and left are equal
		    []
*/

int main(){
	int n;
	int piece;
	int c[100];
	int i;
	int res = 0;
	scanf("%d %d", &n, &piece);

	for(i = 0; i < n;i++){
		scanf("%d", &c[i]);
	}

	switch(piece){
		case 1:
			/*
				[]
				[]
				[]
				[]
			*/
			res += n;
			for(i = 3; i < n; i++){
				/*
					[][][][]
				*/
				if(c[i] == c[i-1] && c[i] == c[i-2] && c[i] == c[i-3]){
					res++;
				}
			}
			break;
		case 2:
			for(i = 1; i < n; i++){
				/*
					[][]
					[][]
				*/
				if(c[i] == c[i-1]){
					res++;
				}
			}
			break;
		case 3:
			/*
				[]
				[][]
				  []
			*/
			if(c[0] == c[1] + 1){
				res++;
			}
			for(i = 2; i < n; i++){
				/*
					  [][]                                         []
					[][]                                           [][]
							    									 []
				*/
				if((c[i] - 1 == c[i-1] && c[i] - 1 == c[i-2]) || (c[i] + 1 == c[i-1])){
					res++;
				}
			}
			break;
		case 4:
			/*
				  []
				[][]
				[]
			*/
			if(c[0] + 1 == c[1]){
				res++;
			}
			for(i = 2; i < n; i++){
				/*
					[][]										  []
					  [][]										[][]
					  											[]
				*/
				if((c[i] == c[i-1] && c[i] == c[i-2] - 1) || (c[i] == c[i-1] + 1)){
					res++;
				}
			}
			break;
		case 5:
			/*
				[]			[]
				[][]	  [][]
				[]			[]
			*/
			if(abs(c[0]-c[1] == 1)){
				res++;
			}
			for(i = 2; i < n; i++){
				/*
					[][][]  implies []
					  []			[][]
					  				[]
				*/
				if(c[i] == c[i-1] + 1 && c[i] == c[i-2]){
					res += 2;
				}
				/*
						  []		[]			  []
						[][][] 		[][]		[][]
									[]			  []
				*/
				else if((c[i] == c[i-1] && c[i] == c[i-2]) || abs(c[i] - c[i-1]) == 1){
					res++;
				}
			}
			break;
		case 6:
			/*
				[]		[][]
				[]		  []
				[][]	  []
			*/
			if(c[0] == c[1] || c[0] == c[1] + 2){
				res++;
			}
			for(i = 2; i < n; i++){
				/*
						[] or  [][][] implies []
					[][][]     []			  []
											  [][]
				*/
				if(c[i] == c[i-1] && (c[i] == c[i-2] || c[i] == c[i-2] + 1)){
					res += 2;
				}
				/*
					[]						[][]
					[]						  []
					[][]					  []
				*/
				else if((c[i] == c[i-1]) || (c[i] + 2 == c[i-1])){
					res++;
				}
			}
			break;
		case 7:
			/*
				  []	[][]
				  []	[]
				[][]	[]
			*/
			if(c[0] == c[1] || c[0] + 2 == c[1]){
				res++;
			}
			for(i = 2; i < n; i++){
				/*
					[]		implies []
					[][][]			[]
								  [][]
				*/
				if(c[i] == c[i-1]  && c[i-1] == c[i-2]){
					res += 2;
				}
				/*
					  []	[][]	[][][]
					  []	[]			[]
					[][]	[]
				*/
				else if((c[i] == c[i-1]) || (c[i] == c[i-1] + 2) || (c[i] + 1 == c[i-2] && c[i] + 1 == c[i-1])){
					res++;
				}
			}
			break;
	}
	printf("%d\n", res);
}