#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100000

typedef struct Node
{
	int id;
	int val;
	struct Node *nei;
	int deg;

}Node;


typedef struct Graph
{
	Node *vertices;
	int size;
}Graph;

