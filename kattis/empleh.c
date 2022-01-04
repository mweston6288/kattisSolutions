#include <stdio.h>
#include <ctype.h>

/*
	Create an ASCII art of a chess board with certain pieces at certain spaces
*/
#define ROW 17
#define COL 33
char board[ROW][COL];

void init(){
	int i,j;
	// set up borders between rows
	for(i = 0; i < ROW;i+=2){
		board[i][0] =  '+';
		for(j = 1; j < COL; j+=4){
			board[i][j] =  '-';
			board[i][j+1] =  '-';
			board[i][j+2] =  '-';
			board[i][j+3] ='+';
		}

	}
	// set up rows 1,3,5,7 which start with a black field
	for(i = 3; i < ROW;i+=4){
		board[i][0] = '|';
		for(j = 1; j < COL; j+=8){
			board[i][j] ='.';
			board[i][j+1] ='.';
			board[i][j+2] ='.';
			board[i][j+3] ='|';
		}
		for(j = 5; j < COL; j+=8){
			board[i][j] =':';
			board[i][j+1] =':';
			board[i][j+2] =':';
			board[i][j+3] ='|';
		}
	}
	// set up rows 2,4,6,8 which start with a white field
	for(i = 1; i < ROW;i+=4){
		board[i][0] = '|';
		for(j = 5; j < COL; j+=8){
			board[i][j] ='.';
			board[i][j+1] ='.';
			board[i][j+2] ='.';
			board[i][j+3] ='|';
		}
		for(j = 1; j < COL; j+=8){
			board[i][j] =':';
			board[i][j+1] =':';
			board[i][j+2] =':';
			board[i][j+3] ='|';
		}
	}
}
void print(){
	int i,j;
	// When building the board, the rows were inverted to make reading inputs easier
	for(i = ROW - 1; i >=0;i--){
		for(j = 0; j < COL;j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
// place a piece at a given panel
// The mathwork is there to compensate for the rows and columns meant to show panel borders
void insertPiece(char piece, int col, int row){
	board[row*2 - 1][2+col*4] = piece;
}
// Read in where each piece is located
// isBlack is a boolean telling whether the chess piece is black or white
void setPieces(int isBlack){
	char p,c;
	int r;
	// clear out "Black: " and "White: "
	for(int i = 0 ; i < 8;i++)
		p = fgetc(stdin);
	// an annoying requirement
	// I couldn't find an effective way to parse whether there were no pieces to begin so
	// I scanned in the very next thing after "Black: " and "White: ".
	// If this is true, it's a chess piece and I have to undo the read
	if (p != '\n' && p != EOF){
		ungetc(p, stdin);
	}
	while (p != '\n' && p != EOF){
		// read first character
		p = fgetc(stdin);
		// pawns are only denoted with their coordinates
		// so if true, this was not a pawn and we can just get the coordinates
		if (isupper(p)){
			c = fgetc(stdin);
		}
		// if false, we have to do some special setup for the pawn
		else{
			c = p;
			p = 'P';
		}
		r = fgetc(stdin) - '0';
		
		// black pieces are lowercase
		if(isBlack){
			p = tolower(p);
		}
		insertPiece(p,c-'a',r);
		// If there's another piece, p will = ','. Otherwise it will be '\n' or EOF
		p = fgetc(stdin);
	}
}
int main(){
	init();
	setPieces(0);
	setPieces(1);
	print();
}