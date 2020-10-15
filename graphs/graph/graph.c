#include "graph.h"

void add_node(Graph *G,Node *n)
{
	for(int x = 0; x < G -> size; x++){
		if(((G->vertices)+x)->id == n->id){
			printf("Node of id: %i is already in the graph.\n",n->id);
			return;
		}
	}
	if(G->size == MAX_SIZE){
		printf("Too many vertices.\n");
		return;
	}
	*((G -> vertices)+(G -> size))  = *n;
	(G->size)++;
	return;
}

void delete_node(Graph *G,int id)
{
	Node *current;
	while((current = (G->vertices)) != NULL){
		
	}
	free(G->vertices + id);


}
