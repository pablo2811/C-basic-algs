#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char letter;
    struct Node **children;
    int isEnd;
    int size;
}Node;


typedef struct Trie
{
    Node *root;
}Trie;

// initialazation
void initialize_Trie(Trie *t){
    Node *root;
    root = (Node*)malloc(sizeof(Node));
    t -> root = root;
    root->letter = '\0';
    root->size = root->isEnd = 0;
}

// check if there is a branch to follow
Node *isNext(Node *nd,char next){
    for(int x = 0; x < nd->size; x++){
        Node *c = *(nd->children + x);
        if(c -> letter == next){
            return(c);
        }
    }
    return NULL;
}

// recursive util adding next letters to trie
void add_util(char *word,Node *act) {
    if (!(*word)) {
        act->isEnd = 1;
    } else {
        Node *next = isNext(act, *word);
        if (next == NULL) {
            if (act->children == NULL) {
                act->children = (Node **) malloc(sizeof(Node*));
            } else {
                act->children = (Node **) realloc(act->children, sizeof(Node*) * (act->size + 1));
            }
            Node *new;
            new = (Node *) malloc(sizeof(Node));
            new->letter = *word;
            *(act->children + act->size) = new;
            act->size += 1;
//        new->size = new->isEnd = 0;
            word++;
            add_util(word, new);
        } else {
            word++;
            add_util(word, next);
        }
    }
}

// add new word to trie
void add(char *word,Trie *t){
    add_util(word,t->root);
}


Node* in_trie(char *word,Node *nd){
    if(!(*word)){
        return(nd);
    }
    Node *n = isNext(nd,*word);
    if(n == NULL){
        return(NULL);
    }else{
        word++;
        return(in_trie(word,n));
    }
}



int count_leaves(Node *n){
    if(!(n->size)){
        return(1);
    }
    int s = 0;
    for(int x = 0; x < n->size;x++){
        s += count_leaves(*(n->children +x));
    }
    return (n->isEnd)?s+1:s;
}

// find number of matches with given prefix


int find_partial(char* partial,Trie *t){
    Node *nd = in_trie(partial,t->root);
    if(nd == NULL){
        return(0);
    }else{
        return count_leaves(nd);
    }

}







// int main(int argc, char const *argv[])
// {
//     Trie *t;
//     t = (Trie*)malloc(sizeof(Trie));
//     initialize_Trie(t);
//     add("kac",t);
//     add("kacper",t);
//     add("kaczynski",t);
//     return 0;
// }