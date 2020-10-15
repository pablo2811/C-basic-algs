#include <stdio.h>

int process_node(int* been,int node,int gs,int relations[gs][gs])
{
	printf("Node %i is being processed\n", node);
	been[node] = 1;
	for(int x = 0; x < gs; x++)
	{
	if (!been[x] && relations[node][x])
	{
	process_node(been,x,gs,relations);
	}
	}
	
}


int dfs(int graph_size,int relations[graph_size][graph_size],int start)
{
	int been[graph_size];
	for(int x = 0 ; x < graph_size ; x++)
	{
	been[x] = 0;
	}
	process_node(been,start,graph_size,relations);
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
	
	dfs(graph_size,relations,0);
}
