#include <stdio.h>
#include <stdlib.h>

/*
	Given two unsorted lists, sort the second so that it is unsorted in the same way as the first
	(the smallest value in the second list is in the same index as the smallest value in the first, etc)

	For this problem, I stored every value in a struct that also has an index. list1 was indexed
	beased on the order I read them in. list2 was not indexed initially.

	Afterward, I sorted both lists by their values, copied the index values from list1 to list2,
	and sorted list2 by index.
*/

// All values were stored in a struct with an index
// this is similar to the index in a python dictionary
typedef struct cell{
	int value;
	int index;
}cell;

// I used mergesort to handle the sorting process
// sortByValue is a boolean that tells the program whether to compare values or index
// if sortValue = 0, we're sorting by index, otherwise we're sorting by value
void merge(cell *list, int low, int mid, int high, int sortByValue){
	
	cell arr[5000];
	int i, length, count1, count2, mc;

	length = high - low + 1;

	count1 = low;
	count2 = mid;
  
	mc = 0;

	while ((count1 < mid) || (count2 <= high)) {
		// check all instances that would cause us to copy from count1
		// check whether count2 is out of bounds and whether we're comparing value or index
		if (count2 > high || (sortByValue && count1 < mid && list[count1].value < list[count2].value) || (!sortByValue && count1 < mid && list[count1].index < list[count2].index)) {
			arr[mc] = list[count1];
			count1++;
			mc++;
		}
		// if the above was false, then we copy from count2
		else {
			arr[mc] = list[count2];
			count2++;
			mc++;
		}
	}
	// copy back
	for (i=low; i<=high; i++){
		list[i] = arr[i - low];
	}

}

void sort(cell *list, int low, int high, int sortByValue){
	if (low < high){
		int mid = (high +low) / 2;
		sort(list, low, mid, sortByValue);
		sort(list, mid+1, high, sortByValue);
		merge(list, low, mid+1, high, sortByValue);
	}

}

int main(){
	int numElements, i;
	cell list1[5000], list2[5000];
	scanf("%d", &numElements);

	while(1){
		// read in list 1, insert indices
		for(i = 0; i < numElements;i++){
			scanf("%d", &(list1[i].value));
			list1[i].index = i;
		}
		// read in list 2, ignore indices
		for(i = 0; i < numElements;i++){
			scanf("%d", &(list2[i].value));
		}
		// sort both lists by value
		sort(list1, 0, numElements-1, 1);
		sort(list2, 0, numElements-1, 1);

		// copy the indices from list1 to list2
		for(i=0; i<numElements;i++){
			list2[i].index = list1[i].index;
		}

		// sort list2 by index
		sort(list2, 0, numElements-1,0);
		
		// print results
		for(i=0; i<numElements;i++){
			printf("%d\n", list2[i].value);
		}
		// get next list size
		scanf("%d", &numElements);
		if (numElements){
			printf("\n");
		}
		else{
			return 0;
		}
	}
}