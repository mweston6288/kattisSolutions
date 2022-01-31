#include <stdio.h>
#include <string.h>
/*
	Use the provided information to find a path from a given branch to the root

	The only thing you can be certain about in each line is the first number is the branch
	that the other branches branch off of. You're not even told which branch is the root.

	Since there's no way to know how many ints are in a line, I have to use fgets() to read the whole line
	and sscanf() to properly evaluate each integer in a line.

	Since sscanf() doesn't have a FILE pointer like fgets() or scanf(), I have to use %n to track the 
	byte count with each scan and use an offset value to determine how far over in the buffer I need to 
	go to find the next int

*/

int main(){
	int loc;
	// this array will track what each branch links to
	// if branches[n] = x, that means you can go from branch n to branch x on your way to the root
	// if branch[n] = 0, that means it's either the root or it wasn't used in the problem
	int branches[101];
	char buffer[520];
	int mainBranch, subBranch;
	// these will be used to help read the buffer
	int n, offset;

	// I have no way to know how many branches there are, so I set everything to 0
	memset(branches, 0, 101*sizeof(int));
	// get initial location
	scanf("%d\n", &loc);
	// get first branch line
	fgets(buffer, 500, stdin);
	do {
		// get main branch of that line
		sscanf(buffer, "%d%n", &mainBranch, &offset);
		// scan the int in the buffer address determined by the offset
		while(sscanf(buffer+offset, "%d%n", &subBranch, &n) == 1){
			branches[subBranch] = mainBranch;
			offset += n;
		}
		// get next branch line
		fgets(buffer, 500, stdin);
	  // The only time buffer[0] is '-' is when I read "-1" from the input, which means input is finished
	} while (buffer[0] != '-');
	// print the path to the root
	printf("%d", loc);
	while(branches[loc] != 0){
		printf(" %d", branches[loc]);
		loc = branches[loc];
	}
	printf("\n");
}