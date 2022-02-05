#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list{
	int index;
	struct list *next;
} list;

list *init(list *head, int n){
	int i;
	list *tail;
	head = malloc(sizeof(list));
	head->index = 0;
	head->next = head;
	tail = head;

	for(int i = 1; i < n; i++){
		tail->next = malloc(sizeof(list));
		tail->next->index = i;
		tail->next->next = head;
		tail = tail->next;
	}
	return head;
}

list *rem(list *l){
	list *temp = l->next;
	l->next = l->next->next;
	free(temp);
	return l->next;
}

int main(){
	int perm[13];
	int numCases, numCards, i, j, k;
	list *l;
	scanf("%d", &numCases);

	for(i = 0; i < numCases; i++){
		scanf("%d", &numCards);
		memset(perm, 0, sizeof(int)*numCards);
		l = init(l, numCards);
		for(j = 1; j <= numCards; j++){
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