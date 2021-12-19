#include <stdio.h>

// prints the excess or missing number of each chess piece

// order : king, queen, rook, bishop, knight, pawn
int main(){
	int king, queen, rook, bishop, knight, pawn;
	scanf("%d %d %d %d %d %d", &king, &queen, &rook, &bishop, &knight, &pawn);
	printf("%d %d %d %d %d %d\n", -(king-1), -(queen-1), -(rook-2), -(bishop-2), -(knight-2), -(pawn-8));
}