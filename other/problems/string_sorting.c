#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_len(const char* a);

int lexicographic_sort(const char* a, const char* b) {
    while(*a == *b){
            a++;
            b++;
        }
    if(*a == '\0' && *b != '\0'){
        return -1;
    }else if(*a != '\0' && *b == '\0'){
        return 1;
    }
        return (*a>*b)?1:-1;
}

int lexicographic_sort_reverse(const char* a, const char* b) {

    while(*a == *b){
            a++;
            b++;
        }
    if(*a == '\0' && *b != '\0'){
        return 1;
    }else if(*a != '\0' && *b == '\0'){
        return -1;
    }
        return (*a>*b)?-1:1;

}

int distinct(const char* a){
    int seen[26],res = 0;
    for(int x = 0; x < 26 ; x++){
        seen[x] = 0;
    }
    char c;
    while((c=*a) != '\0'){
        if(seen[c-97] == 0){
            seen[c-97] = 1;
            res++;

        }
        a++;
    }
    return res;
}


int sort_by_number_of_distinct_characters(const char* a, const char* b){
    int a_d = distinct(a);
    int b_d = distinct(b);
    if(a_d > b_d){
        return 1;
    }else if(a_d < b_d){
        return -1; 
    }
    return lexicographic_sort(a,b);
}

int get_len(const char* a){
    char c;
    int counter = 0;
    while((c=*a) != '\0'){
        counter++;
        a++;
    }
    return counter;
}



int sort_by_length(const char* a, const char* b) {
    int a_d = get_len(a);
    int b_d = get_len(b);
    if(a_d > b_d){
        return 1;
    }else if(a_d < b_d){
        return -1; 
    }
    return lexicographic_sort(a,b);
}

void swap(char **a, char **b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}




void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 0; i < len; i++){
        for(int j = 1; j < len; j++){
            if(cmp_func(arr[j-1],arr[j]) == 1){
                swap(arr+j-1,arr+j);
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    printf("******************************\n");
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
        printf("******************************\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
        printf("******************************\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");
        printf("******************************\n");


    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}