#include <stdlib.h>

typedef struct Node Node;
typedef struct Elem
{
	struct Elem *next;
	struct Elem *prev;
	struct Node *nd;
}Elem;

typedef struct Queue
{
	struct Elem *start;
	struct Elem *end;
}Queue;

Elem* pop_queue(Queue *Q);
void add_to_queue(Queue *Q, Node *n);

