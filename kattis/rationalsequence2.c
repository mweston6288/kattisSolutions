#include <stdio.h>
/*
	Given a binary tree with the following characterisitics:
	each node stores a rational number = p/q
	the root node (node 1) = 1/1
	the left child of node n = p/(p+q)
	the right child of node n = (p+q)/q

	Given a value of p and q, determine which node n is storing it when traversing with breadth-first search

	Since we're using breadth-frsth search, the root is node 1, it's left is node two, it's right is node 3,
	node 2's left is node 4, etc.

	Let n be the node that a given rational number is stored in
	f(n) = p/q
	If p > q, n is the right child of node n/2
	If p < q, n is the left child of node n/2
	If p = q, we're at the root
	Node n's left child = 2*n
	n's right child = 2*n+1
*/
// recursively travel up the tree to figure out which node the number was in
int findSpot(int p, int q){
	// can only happen at the root
	if (p == q){
		return 1;
	}
	// if this was a left child, multiply by 2
	if (p < q){
		return 2 * findSpot(p, q-p);
	}
	// if this was a right child, multiply by 2 and add 1
	return 2 * findSpot(p-q, q) + 1;
}
int main(){
	int numCases, p,q, j;
	scanf("%d", &numCases);

	for (int i = 1; i <= numCases;i++){
		scanf(" %d %d/%d", &j, &p, &q);
		printf("%d %d\n", j, findSpot(p,q));
	}

}