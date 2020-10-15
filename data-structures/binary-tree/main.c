#include <stdio.h>

#include "binary-tree.h"


int main(int argc, char const *argv[])
{
	BinaryTree *b = (BinaryTree*)malloc(sizeof(BinaryTree));
	int n;
	scanf("%i",&n);
	while(n--)
	{
		int val;
		scanf("%i",&val);
		add_vertice(b,val);
	}
	bfs_print(b);
	dfs_print(b);
	printf("There are %i pairs of first cousins.\n", common_grandpa(b));


	return(0);

}