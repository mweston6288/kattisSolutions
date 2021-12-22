#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	Given a boat with P parts that are replaced over N days, determine how many days
	it takes for the boat to be fully replaced
*/
// store previous parts in a binary search tree
typedef struct part{
	char name[22];
	struct part *left;
	struct part *right;
} part;

// make a new node for the tree
part *buildNode(char *name){
	part *new = malloc(sizeof(part));
	new->left = new->right = NULL;
	strcpy(new->name, name);
	return new;
}

// use pointers to handle making new nodes
// returns 1 when a new part is replaced and 0 if a previously replaced part is replaced
int addToList(char *name, part **root){

	// base case: name was not found. Add it in
	if(*root == NULL){
		*root = buildNode(name);
		return 1; 
	}
	int cmp = strcmp(name, (*root)->name);
	// root->name == name. Make no changes
	if (!cmp)
		return 0;
	// name comes before root->name, travel right
	if (cmp > 0){
		return addToList(name, &((*root)->right));
	}
	// name comes after root->name, travel left
	return addToList(name, &((*root)->left));

}
// free all the memory space recursively
part *freeNodes(part *root){
	if (root == NULL){
		return NULL;
	}
	freeNodes(root->left);
	freeNodes(root->right);
	free(root);
	return NULL;
}

int main(){
	int numParts, numDays;
	scanf("%d %d", &numParts, &numDays);

	part *list = NULL;
	char partName[22];
	int numReplaced = 0;
	for(int i = 1; i <= numDays;i++){
		scanf("%s", partName);
		numReplaced += addToList(partName, &list);
		// as soon as all parts are replaced, post the result
		if(numReplaced == numParts){
			printf("%d\n", i);
			freeNodes(list);
			return 0;
		}
	}
	printf("paradox avoided\n");
	freeNodes(list);

}