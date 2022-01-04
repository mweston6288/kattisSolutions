#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
	Given a list of friends, their birthdays, and how much you like them,
	print how many unique birthdays they have and then print, in alphabetic order, the friends you like most
	for each birthday

	Process done in this solution:
		1) Read in each person into an array
		2) Sort the array by birthday, then by like
		3) Remove names from the array with matching birthdays
		4) Sort the array by name
		5) Print
*/

// each friend object
typedef struct friend{
	char name [11];
	int likes;
	int day;
	int month;
} friend;

// create a friend
friend *makeFriend(char *name, int likes, int day, int month){
	friend *new = malloc(sizeof(friend));
	strcpy(new->name, name);
	new->likes = likes;
	new->day = day;
	new->month = month;
	return new;
}

void swap (friend **a, friend **b){
	friend *temp = *a;
	*a = *b;
	*b = temp;
}
// a comparator function
/*
	CompMethod determines how to compare
		if compMethod == 1, compare birthdays, then like
		if compMethod == 0, compare names
*/
int comparator(friend *a, friend*b, int compMethod){
	if(compMethod){
		/*
			Return 1 if either
				1) a's birthmonth comes before b's
				2) a and b's birthmonth is the same and either
					2a) a's birthdate comes before b's
					2b) a and b's birthdate is the same and a's like is higher than b's
		*/
		if (a->month < b->month || (a->month == b->month && (a->day < b->day || (a->day == b->day && a->likes > b->likes)))){
			return 1;
		}
	}
	else {
		// return 1 if a's name comes before b's alphabetically
		if(strcmp(a->name, b->name) < 0){
			return 1;
		}
	}
	return 0;
}
// general idea with partition here is we move all elements less than the pivot to the front
int partition(friend **list, int low, int high, int compMethod){
	int pivot = high;
	// i is used to determine where elements less than the pivot are going to go
	int i = low;
	high--;
	for (int j = low; j <= high; j++) {
		// if j should be before pivot, we move j toward the front
		if (comparator(list[j], list[pivot], compMethod)){ 
			swap(&list[i], &list[j]); 
			i++;

		} 
	} 
	// swap the pivot into where it should go
	swap(&list[i], &list[pivot]); 

	return i; 
}
// It's quicksort
void sort(friend **list, int low, int high, int compMethod){
	if(low < high){
		int p = partition(list, low, high, compMethod);

		sort(list, low, p-1, compMethod);
		sort(list, p+1, high, compMethod);
	}
}
// reduce the array to only the friends you like the most for each unique birthday
// We're guaranteed list is sorted by birthday and then like in descending order
// list will be modified during this function
// unnecessary data will be discarded while required elements are moved closer to the front
// this returns the number of remaining elements
int reduce(friend **list, int n){
	// i will be the friend to compare
	int i = 0, j, res = n;
	for(j = 1; j < n;j++){
		// if i and j have the same birthday, delete j because i is liked more than j
		if(list[i]->month == list[j]->month && list[i]->day == list[j]->day){
			free(list[j]);
			res--;
		}
		// if i and j have different birthdays, relocate j to be adjancent to i
		// the next friend will be compared to j
		else{
			i++;
			list[i] = list[j];
		}
	}
	return res;
}

int main(){
	friend **list;
	int numFriends, i;
	scanf("%d\n", &numFriends);

	// make the list of friends
	list = malloc(sizeof(friend*)*numFriends);
	char name[11];
	int likes,month,day;
	for(i = 0; i < numFriends;i++){
		scanf("%s %d %d/%d\n", name, &likes,&day,&month);
		list[i] = makeFriend(name, likes,day,month);
	}
	// sort them by birthday
	sort(list, 0, numFriends-1, 1);
	// remove friends with mathcing birthdays
	numFriends = reduce(list, numFriends);
	// sort them by name
	sort(list, 0 , numFriends-1, 0);
	// print the results
	printf("%d\n", numFriends);
	for(i = 0; i < numFriends;i++){
		printf("%s\n", list[i]->name);
	}
	// cleanup
	for(i = 0; i < numFriends;i++){
		free(list[i]);
	}
	free(list);
}