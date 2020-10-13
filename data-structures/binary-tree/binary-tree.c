
#include "binary-tree.h"
#include "queue.h"
// BinaryTree implemetation


void add_vertice(BinaryTree *B,int v)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node -> val = v;
	new_node -> left = new_node -> right = NULL;
	if(B -> root == NULL)
	{
		B -> root = new_node;
		B -> root -> depth = 0;
		return;
	}

	Node *current = B->root;
	while(current != NULL)
	{
		if(current -> val == v){
			printf("Value %i already in BST\n",v);
			return;
		}
		if(v > (current -> val)){
			 if((current -> right) == NULL){
				current -> right = new_node;
				new_node -> depth = (current -> depth) + 1;
				return;
			}else{
				current = current -> right;
			}
		
	}else{
		if((current -> left) == NULL){
			current -> left = new_node;
			new_node -> depth = (current -> depth) + 1;
			return;
		}else{
			current = current -> left;
		}
	}
	}
}

void dfs_util_print(Node *nd){
	if(nd -> left != NULL)
	{
		dfs_util_print(nd->left);
	}
	if(nd -> right != NULL)
	{
		dfs_util_print(nd->right);
	}
	printf("%5i",nd->val);

}

void dfs_print(BinaryTree *B){
	if(B->root == NULL){
		return;
	}
	dfs_util_print(B->root);
	printf("\n");
}



int process_node(Node *n)
{
	if(n->right == NULL && n->left == NULL){
		return(n->depth);
	}
	int M = ((n -> right) == NULL) ? -1 : process_node(n->right);
	int m = ((n -> left) == NULL) ? -1 : process_node(n->left);
	return (M > m) ? M : m;
}



int max_depth(BinaryTree *B)
{

	return process_node(B->root);

}

void bfs_print(BinaryTree *B){
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	if(B->root == NULL){
		return;
	}
	add_to_queue(Q,B->root);
	while(Q -> start != NULL){
		Elem *e = pop_queue(Q);
		printf("%5i", e->nd->val);
		if(e->nd->left != NULL){
			add_to_queue(Q,e->nd->left);
			
		}
		if(e->nd->right != NULL){
			add_to_queue(Q,e->nd->right);
			
		}
	}
	printf("\n");

}
