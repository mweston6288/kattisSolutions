#include <stdio.h>
#include <string.h>
/*
	Get all unique compound words in sorted order

	Step process:
		Read in all words
		Create every compound word
		Sort the list
		Remove repeat values
*/
// Create each possible compound word
// takes in the inital list, the list to store the results, and the number of initial words
// returns the number of compound words
int build(char s[][11], char res[][21], int n){
	int i,j,k=0;
	for(i = 0; i < n;i++){
		// we can't concatenate a word to itself
		// this first loop concatenates s[i] to everything before it
		for(j = 0; j < i;j++){
			strcpy(res[k], s[i]);
			strcat(res[k++], s[j]);
		}
		// this loop concatenates to eveything after it
		for(j++; j < n; j++){
			strcpy(res[k], s[i]);
			strcat(res[k++], s[j]);
		}
	}
	return k;
}

void swap(char *s1, char *s2){
	char temp[11];
	strcpy(temp, s1);
	strcpy(s1,s2);
	strcpy(s2, temp);
}
// insertion sort
void sort(char s[][21], int n){
	int i,j;
	for(i = 1; i < n;i++){
		for(j = i; j > 0; j--){
			if (strcmp(s[j], s[j-1])< 0){
				swap(s[j], s[j-1]);
			}
			else{
				break;
			}
		}
	}
}

// remove duplicate strings
// res is guaranteed to be sorted
// non-duplicate string are pushed to lower indices in res
// returns the number of strings after reduction
int minimize(char res[][21], int n){
	// k is the index the next unique string will be placed
	int k = 1;
	for(int i = 1; i < n;i++){
		// if res[i] is different from the previous string,
		// relocate it to index k
		if (strcmp(res[i], res[i-1])){
			strcpy(res[k++], res[i]);
		}
	}
	return k;
}

int main(){
	char s[100][11];
	char res[1000][21];
	int n = -1;
	// read the strings and count them
	while(scanf("%s", s[++n]) == 1);
	// make the compound words
	n = build(s, res, n);
	// sort them
	sort(res, n);
	// remove redundencies
	n = minimize(res, n);
	for(int i = 0; i < n;i++){
		printf("%s\n", res[i]);
	}
}
