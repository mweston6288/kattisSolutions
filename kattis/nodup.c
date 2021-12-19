#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// check if a serires of words have duplicate words

// I'll store them in a binary tree. If any word matches a previous stored word, then I end early and return fail

typedef struct word{
	char name[82];
	struct word *left;
	struct word *right;
} word;

// make a new node for the tree
word *buildNode(char *name){
	word *new = malloc(sizeof(word));
	new->left = new->right = NULL;
	strcpy(new->name, name);
	return new;
}

// takes in a word name, a word node, and a pointer to the response
// recursively traverses the tree until it determines if any node has the same name as the one passed in
// if name is already in the tree, set res to 0 and return;
word *addToList(char *name, word *root, int *res){
	// base case: name was not found. Add it in
	if(root == NULL){
		word *new = buildNode(name);
		return new; 
	}
	int cmp = strcmp(name, root->name);
	// root->name == name. Make no changes
	if (!cmp){
		*res = 0;
		return root;
	}
	// name comes before root->name, travel left
	if (cmp > 0){
		root->right = addToList(name, root->right, res);
		return root;
	}
	// name comes after root->name, travel right
	root->left = addToList(name, root->left, res);
	return root;
}
// free all the memory space recursively
word *freeNodes(word *root){
	if (root == NULL){
		return NULL;
	}
	freeNodes(root->left);
	freeNodes(root->right);
	free(root);
	return NULL;
}
int main(){
	char string[82];
	word *c = NULL;
	int res = 1;
	while (scanf("%s", string) == 1){
		c = addToList(string, c, &res);
		if (!res){
			printf("no\n");
			freeNodes(c);
			return 0;
		}
	}
	printf("yes\n");
	freeNodes(c);
	return 0;
}