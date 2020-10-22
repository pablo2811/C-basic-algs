#include <stdio.h>
#include <stdlib.h>

#define MAXHEAP 100000

typedef struct Heap{
    int *core;
    int capacity;
    int size;

}Heap;

int* find_max(Heap *h){
    return (h->size > 0) ? h -> core : NULL;
}
int up_heap(Heap *h, int start)
{
    // start = index
    if(!(h -> size)){
        return -1;
    }
    if(!start){
        return start;
    }
    int *next = h -> core + (start-1)/2;
    int *current = h -> core + start;
    while(start >= 0 && *next < *current){

        int t = *current;
        *current = *next;
        *next = t;
        start = start / 2;
        next = h -> core + (start)/2;
        current = h -> core + start;
    }
    return start;
}

int down_heap(Heap *h,int start){
    if(!(h->size)){
        return -1;
    }
    int next = 2*start + 1;
    int *c  = h->core + start;
    if(next + 1 < h->size){
        int better = (*((h->core) + next + 1) < *((h->core) + next)) ? next : next + 1;
        int *n = h->core + better;
        if(*n < *c){
            return start;
        }else{
            int t = *n;
            *n = *c;
            *c = t;
            return down_heap(h,better);
        }
    }else if(next < h->size){
        int *son = h->core + next;
        if(*son > *c){
            int t = *son;
            *son = *c;
            *c = t;
            return next;

        }

    }else{
        return start;
    }

}

void correct(Heap *h, int old_val,int new_val,int i){
    if(new_val > old_val){
        up_heap(h,i);
        return;
    }else{
        down_heap(h,i);
    }
}

void replace_util(Heap *h,int *i,int *j){
    int t = *i;
    *i = *j;
    *j = t;
}
void replace(Heap *h, int i, int j){
    int old_x = *(h->core + i);
    int old_y = *(h->core +j);
    replace_util(h,h->core+i,h->core+j);
    correct(h,old_x,*(h->core + i),i);
    correct(h,old_y,*(h->core + j),j);
}

void remove_last(Heap *h){
    if(h->size){
        (h->size)--;
    }
    if((h->capacity)/2 > h->size){
        h->core = (int*)realloc(h->core,(h->capacity)/2);
    }
}


int extract(Heap *h){
    int val = *find_max(h);
    replace_util(h,h->core + h->size - 1,h->core);
    remove_last(h);
    correct(h,val,*(h->core),0);
    return val;


}
void print_heap_util(Heap *h,int i){
    printf("%i  ",*(h->core+i));
    int next_left = 2*i+1;
    if(next_left < h-> size){
        print_heap_util(h,next_left);
    }
    if(next_left + 1 < h->size) {
        print_heap_util(h, next_left + 1);
    }
}
void print_heap(Heap *h){
    if(h->size){
        print_heap_util(h,0);
        printf("\n");
    }else{
        printf("Heap is empty.\n");
    }
}


void insert(Heap *h, int v){
    if(h->size > MAXHEAP){
        printf("Memory allocation error, heap is overloaded");
        return;
    }
    if(!h->capacity){
        h -> core = (int *)malloc(sizeof(int));
        h -> capacity = 1;
    }
    if(h->size >= h->capacity){
        h -> core = (int *)realloc(h -> core,2*h->capacity);
        h -> capacity *= 2;
    }
    *((h -> core) + h -> size)  = v;
    up_heap(h,h->size);
    (h->size)++;


}

// int main(int argc, char const *argv[])
// {
//     Heap *h = (Heap *)malloc(sizeof(Heap));
//     insert(h,10);
//     insert(h,2);
//     insert(h,13);
//     insert(h,5);
//     replace(h,0,3);
//     print_heap(h);
//     int v = extract(h);
//     printf("%i\n",v);
//     print_heap(h);
//     return 0;
// }
