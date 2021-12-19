#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// find the number of unique city names in a list
// this soultion uses a binary search tree to reduce comparisons

// stores city name and two references
// left is a city that comes alphabetically before 
// right is a city that comes alphabetically after
typedef struct city{
	char name[22];
	struct city *left;
	struct city *right;
} city;

// make a new node for the tree
city *buildNode(char *name){
	city *new = malloc(sizeof(city));
	new->left = new->right = NULL;
	strcpy(new->name, name);
	return new;
}

// takes in a city name, a city node, and a pointer to the number of unique nodes
// recursively traverses the tree until it determines if any node has the same name as the one passed in
// if name is already in the tree, just return
// otherwise, add a new node and increment res
city *addToList(char *name, city *root, int *res){
	// base case: name was not found. Add it in
	if(root == NULL){
		city *new = buildNode(name);
		(*res)++;
		return new; 
	}
	int cmp = strcmp(name, root->name);
	// root->name == name. Make no changes
	if (!cmp)
		return root;
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
city *freeNodes(city *root){
	if (root == NULL){
		return NULL;
	}
	freeNodes(root->left);
	freeNodes(root->right);
	free(root);
	return NULL;
}

int main(){
	int numCases;
	scanf("%d", &numCases);
	int i,j, numCities, res;
	char temp[22];
	city *c = NULL;
	for(i = 0; i < numCases; i++){
		res = 0;
		scanf("%d", &numCities);
		// add each city to the tree and count the number of successes
		for(j = 0; j < numCities; j++){
			scanf("%s", temp);
			c = addToList(temp, c, &res);
		}
		printf("%d\n", res);
		// free everything before starting over
		c = freeNodes(c);
	}

}