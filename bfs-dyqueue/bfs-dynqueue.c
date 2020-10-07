#include <stdio.h>
#include <stdlib.h>



void push(int *queue,int *c_size,int in,int value)
{
	if(in > *c_size)
	{
		void* tmp = realloc(queue,2*sizeof(queue));
		*c_size *= 2;
	}
	queue[in] = value;

}


int get(int *queue,int *c_size)
{
	int him = *queue;
	for(int i = 0; i < *c_size-1;i++)
	{
		queue[i] = queue[i+1];
	}
	queue[*c_size-1] = -1;
	*c_size -= 1;
	return him;
}

// void print_queue(int *queue,int size)
// {
// 	for(int x = 0; x < size; x++)
// 	{
// 		if(*(queue+x) != -1)
// 			printf("%i ",*(queue+x));
// 	}
// }


void bfs(int graph_size, int relations[graph_size][graph_size],int start)
{
	int* queue = (int *) malloc(graph_size);
	int been[graph_size];
	for(int x = 0; x < graph_size; x++)
	{
		queue[x] = -1;
		been[x] = 0;
	}
	queue[0] = start;
	been[0] = 1;
	int size = graph_size;
	int last = 1;
	while(queue[0] != -1)
	{
		int val = get(queue,&size);
		last--;
		printf("Processing node %i.\n",val);
		for(int x = 0; x < graph_size; x++)
		{
		if(relations[val][x] && !been[x])
		{
			push(queue,&size,last,x);
			been[x] = 1;
			++last;
		}
		}
	
	}

}


int main()
{
	int graph_size, edges;
	scanf("%i %i",&graph_size,&edges);
	int relations[graph_size][graph_size];
	for(int x = 0 ; x < graph_size; x++)
	{
		for(int w = 0; w <graph_size; w++)
		{
		relations[x][w] = 0;
		}
	}
	for(int x = 0; x < edges; x++)
	{
		int a,b;
		scanf("%i %i",&a,&b);
		if ( a < graph_size && b < graph_size)
		{
		relations[a][b] = 1;
		relations[b][a] = 1;
		}
	}
	bfs(graph_size,relations,0);
}
