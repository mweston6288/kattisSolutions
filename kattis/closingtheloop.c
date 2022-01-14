#include <stdio.h>

/*
	To create the maximum length loop from alternating colors, get the biggest of each color,
	then the second biggest, etc. Repeat until you've used all the pieces of one color

	each knot cost 1cm of length. Since we're making a loop, n rope pieces will have n knots
*/
typedef struct rope rope;

struct rope {
	int len;
	char color;
};
// radix sort
void sort(rope *r, int n){
	rope output[n];
	int i, count[10];
	int x;

	for (int exp = 1; 100 / exp > 0; exp *= 10){
		// initialize counting array
		for(i = 0; i < 10;i++){
			count[i] = 0;
		}
		// count how many elements have particular values at particular digits
		for (i = 0; i < n; i++){
			count[(r[i].len / exp) % 10]++;
		}
	
		// set count value
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// copy array to an aux array
		for (i = n - 1; i >= 0; i--) {
			x = r[i].len / exp % 10;
			output[--count[x]].len = r[i].len;
			output[count[x]].color = r[i].color;
		}
		// copy it back in
		for (i = 0; i < n; i++){
			r[i].len = output[i].len;
			r[i].color = output[i].color;
		}
	}
}

// search through the sorted array to find the pair of biggest pieces of each color
// then the second biggest, etc and sum their lengths
int getLen(rope *r, int n){
	int len = 0;
	int i=n,j=n;

	while (i >= 0 && j >= 0){
		// find the logest unused piece for one color
		do{
			i--;
		} while (i >= 0 && r[i].color != 'B' );
		// find the logest unused piece for another color
		do{
			j--;
		} while (j >= 0 && r[j].color != 'R' );
		// if found, tie them to the loop
		// 2 knots are made so -2 cm
		if(i >= 0 && j >= 0)
			len += (r[i].len + r[j].len - 2);
	}
	return len;
}

int main(){
	int numCases,i,j,n;
	rope r[1000];
	scanf("%d\n", &numCases);

	for(i = 1; i <= numCases;i++){
		scanf("%d\n", &n);
		for(j = 0; j < n;j++){
			scanf("%d%c\n", &(r[j].len), &(r[j].color));
		}
		sort(r,n);

		printf("Case #%d: %d\n", i, getLen(r,n));

	}
}