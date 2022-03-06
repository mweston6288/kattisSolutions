#include <stdio.h>
#include <string.h>

/*
	Sort a list of names based only on the first two letters of their names
	When comparing two names, organize them using the following rules:
		1) Whichever name has the lower ASCII value in index 0 goes first
		2) If the above is a tie, whichever name has the lower ASCII value in index 1 goes first
		3) If the above is a tie, the first name goes first

	The sorted array needs to be a stable sort. I opted to use Merge sort for it
*/

// return 1 if name1 comes before name2
// 0 otherwise
int checkSort(char *name1, char *name2){
	// all reasons name1 would go first
	if (name1[0] < name2[0] || (name1[0] == name2[0] && name1[1] <= name2[1])){
		return 1;
	}
	return 0;
}
// mergesort
void merge(char names[][21], int low, int mid, int high){
	
	char arr[200][21];
	int i, length, count1, count2, mc;

	length = high - low + 1;

	count1 = low;
	count2 = mid;
  
	mc = 0;

	while ((count1 < mid) || (count2 <= high)) {
		// check all instances that would cause us to copy from count1
		// check if count2 is out of bounds or if count1 is inbounds and should go first
		if (count2 > high || (count1 < mid && checkSort(names[count1], names[count2]))) {
			strcpy(arr[mc++], names[count1++]);
		}
		// if the above was false, then we copy from count2
		else {
			strcpy(arr[mc++], names[count2++]);
		}
	}
	// copy back to the main index
	for (i=low; i<=high; i++){
		strcpy(names[i], arr[i-low]);
	}

}

void sort(char names[][21], int low, int high){
	if (low < high){
		int mid = (high +low) / 2;
		sort(names, low, mid);
		sort(names, mid+1, high);
		merge(names, low, mid+1, high);
	}

}
void printList(char names[][21], int n){
	for (int i = 0; i < n; i++){
		printf("%s\n", names[i]);
	}
	printf("\n");
}
int main(){
	int num, i;
	char names[200][21];
	scanf("%d", &num);

	do{
		for(i = 0; i < num; i++){
			scanf("%s", names[i]);
		}
		sort(names, 0, num-1);
		printList(names, num);
		scanf("%d", &num);
	} while (num != 0);
}