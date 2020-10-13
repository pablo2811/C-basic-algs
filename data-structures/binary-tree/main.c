#include <stdio.h>

#include "binary-tree.h"


int main(int argc, char const *argv[])
{
	BinaryTree *b = (BinaryTree*)malloc(sizeof(BinaryTree));
	add_vertice(b,10);
	add_vertice(b,5);
	add_vertice(b,12);
	add_vertice(b,1);
	bfs_print(b);
	dfs_print(b);
	return(0);

}