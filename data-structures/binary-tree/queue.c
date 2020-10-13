#include "queue.h"


Elem* pop_queue(Queue *Q)
{
	Elem* ret = Q -> start;
	Q -> start = Q -> start -> prev;
	return(ret);

}
void add_to_queue(Queue *Q,Node *n){
	Elem *e = (Elem*)malloc(sizeof(Elem));
	e -> nd = n;
	if(Q -> start == NULL){
		Q -> end = Q -> start = e;
		return;
	}
	e -> next = Q -> end;
	Q -> end -> prev = e;
	Q -> end = e;
	return;
}
