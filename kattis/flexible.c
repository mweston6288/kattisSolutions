#include <stdio.h>

/*
	Find all the possible partition sizes given a rectangle of width w and several partitions located 
	a certain distance from the left wall

	a partition wall located n units from the left wall can make a partition size of n and w-n
	Then for each partition wall n1 and n2, you can make a partition of size n2-n1

	Personally, I would have liked to use bitwise operations to store things as booleans,
	but I'd need potentially 100 bools due to the problem scope and long long is only guaranteed to have 64 bits.
	The logistics in using 2 long longs and checking which one to use was more trouble than it was worth.
	I did use chars instead since they're only 8 bits so there's less wasted space.
*/
int main(){
	int w,numPart,i,j;
	char bools[101];
	int part[100];
	scanf("%d %d", &w, &numPart);
	// init
	for(i = 0; i < w;i++){
		bools[i] = 0;
	}
	// read in each partition wall location
	// and determine what partition sizes can be made with them
	for(i = 0; i < numPart;i++){
		scanf("%d", &part[i]);
		// partition sizes made using only part[i]
		bools[part[i]] = 1;
		bools[w-part[i]] = 1;
		// get sizes that can be made from part[i] with all previous partitions
		for(j = i-1; j >= 0; j--){
			bools[part[i]-part[j]] = 1;
		}
	}
	// print the partitions made with walls
	for(i = 1; i < w;i++){
		if(bools[i]){
			printf("%d ", i);
		}
	}
	// print the full room size when none are used
	printf("%d\n", w);


}