#include <stdlib.h>
#include <stdio.h>


typedef struct Node
{
	int val;
	int depth;
	struct Node *left;
	struct Node *right;
}Node;


typedef struct BinaryTree
{
	Node *root;
}BinaryTree;



void add_vertice(BinaryTree *B,int v);
void dfs_util_print(Node *nd);
void dfs_print(BinaryTree *B);
int process_node(Node *n);
int max_depth(BinaryTree *B);
void bfs_print(BinaryTree *B);
int common_grandpa(BinaryTree *b);




