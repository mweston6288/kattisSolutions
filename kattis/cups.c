#include <stdio.h>
#include <ctype.h>

/*
	paired sets of colors and numbers are passed in
	If color is passed in first, just record the values
	If number is passed in first, divide the number in half

	Print the colors in ascending order of their associated numbers
*/

// stores the data in one set
typedef struct cup{
	int r;
	char s[21];
} cup;

void swap(cup *a, cup *b){
	cup temp = *a;
	*a = *b;
	*b = temp;
}
// inserttion sort because n will never be greater than 20
void sort (cup cups[], int n){
	int i,j;
	for(i = 1; i < n;i++){
		for(j = i; j > 0; j--){
			if (cups[j].r < cups[j-1].r){
				swap(&cups[j], &cups[j-1]);
			}
			else{
				break;
			}
		}
	}
}
int main(){
	cup cups[20];
	int n,i;
	char c;
	scanf("%d\n", &n);
	
	for(i = 0; i < n; i++){
		// get the first char to determine if the color or number came first
		c = getc(stdin);
		if(isalpha(c)){
			// I already have the first letter so I might as well just store it in
			// and get the rest of the word
			cups[i].s[0] = c;
			scanf("%s %d\n", &(cups[i].s[1]), &(cups[i].r));
		}
		else{
			// not worth the hassle figuring out a number's numeric value
			// just unget and then scan in the full number
			ungetc(c, stdin);
			scanf("%d %s\n", &(cups[i].r), cups[i].s);
			// required mod
			cups[i].r /= 2;
		}
	}
	// sort and print
	sort(cups, n);
	for(i = 0; i < n; i++){
		printf("%s\n", cups[i].s);

	}
}