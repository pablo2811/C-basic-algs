#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int id;
	struct Node *parent;
	struct Node **children;
	int nei;
	int *colors;
}Node;

typedef struct Tree
{
	Node **allNodes;
	int size;
}Tree;







int main(int argc, char const *argv[])
{
	int n,a,b;
	scanf("%i",&n);
	Tree *t;
	t -> size = n;
	t -> allNodes = (Node**)malloc(sizeof(Node*)*n);
	for(int x = 0; x < n; x++){
		Node *nd;
		nd -> id = x + 1;
		nd -> parent = (Node*)malloc(sizeof(Node));
		nd -> children = (Node**)malloc(sizeof(Node*)*n);
		nd -> colors = (int*)malloc(sizeof(int)*n);
		nd -> nei = 0;
		*(t -> allNodes+x) = nd;
	}
	for(int x = 0; x < n - 1; x++){
		int a,b;
		char c;
		scanf("%i %i %c",&a,&b,&c);
		

	}



	return 0;
}