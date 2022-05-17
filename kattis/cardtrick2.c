#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
	Determine how to set up a deck to do the following trick:
		Take the top card and place it at the bottom. Then draw the top card. It's an ace
		Take the top two cards and place them at the bottom of the deck. Draw the top card. It's a two
		Each cycle, take the top n cards and put them at the bottom of the deck and then draw a card 
			which will have a value n

	For this problem, I created a circular linked list which represent the spot in the deck each card is
	at when the trick begins. For each card, I cycle through the deck as many times as I need to to find
	what spot in the deck the card needs to be. Then I mark that spot in an array and remove it from the deck
*/
// The "card". Rather than storing the card value, it stores it's place in the deck
typedef struct list{
	int index;
	struct list *next;
} list;

// set up the linked list
// n is the number of cards
list *init(list *head, int n){
	int i;
	list *tail;
	// set up very first item
	head = malloc(sizeof(list));
	head->index = 0;
	head->next = head;
	tail = head;

	// create and attach each element
	for(int i = 1; i < n; i++){
		tail->next = malloc(sizeof(list));
		tail->next->index = i;
		tail->next->next = head;
		tail = tail->next;
	}
	return head;
}

// remove the next element in the list
// l is the list item that points to the item to remove
list *rem(list *l){
	list *temp = l->next;
	l->next = l->next->next;
	free(temp);
	return l->next;
}

int main(){
	// perm stores the final answer
	int perm[13];
	int numCases, numCards, i, j, k;
	list *l;
	scanf("%d", &numCases);

	for(i = 0; i < numCases; i++){
		scanf("%d", &numCards);
		memset(perm, 0, sizeof(int)*numCards);
		l = init(l, numCards);
		// cycle through the deck for each card
		for(j = 1; j <= numCards; j++){
			// cycle through the deck to find where each specific card will be
			// I want to cycle 1 less so I can remove the card I need to
			// rem will take care of the final jump
			for(k = 1; k < j; k++){
				l = l->next;
			}
			perm[l->next->index] = j;
			l = rem(l);
		}
		printf("%d", perm[0]);
		for(j = 1; j < numCards;j++){
			printf(" %d", perm[j]);
		}
		printf("\n");
	}
}