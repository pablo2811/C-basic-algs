#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);


// int bs(int val,int *b,int L,int R,int s){
//     if(L == R){
//         return L;
//     }
//     int M = (L+R)/2;
//     int v = b[M];
//     while(M < s && b[M] == val){
//     	M++;
//     }
//     if(b[M] >= val){
//         return bs(val,b,L,M,s);
//     }else{
//         return bs(val,b,M+1,R,s);
//     }

// }
int alone(int *arr,int start,int top){
    int x = start;
    while(x >= 0 && arr[x] > top){
        x -= 1
    }
    return x + 1;
}

int twoStacks(int x, int a_count, int* a, int b_count, int* b) {
    for(int z = 1; z < a_count; z++){
        a[z] += a[z-1];
    }
    for(int z = 1; z < b_count; z++){
        b[z] += b[z-1];
    }
    int counter = 0
    int a_al = alone(a,a_count-1,x);
    int b_al = alone(b,b_count-1,x);
    int max_inds = (a_al < b_al) ? b_al : a_al;
    int R = b_count - 1;
    for(int z = 0; z < a_count;z++){
        R = alone(b,R,x - a[z]);
        if(R + z + 1> max_inds){
            max_inds = R + z + 1;
        }
        R--;
    }
    
    return max_inds;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* g_endptr;
    char* g_str = readline();
    int g = strtol(g_str, &g_endptr, 10);

    if (g_endptr == g_str || *g_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int g_itr = 0; g_itr < g; g_itr++) {
        char** nmx = split_string(readline());

        char* n_endptr;
        char* n_str = nmx[0];
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char* m_endptr;
        char* m_str = nmx[1];
        int m = strtol(m_str, &m_endptr, 10);

        if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

        char* x_endptr;
        char* x_str = nmx[2];
        int x = strtol(x_str, &x_endptr, 10);

        if (x_endptr == x_str || *x_endptr != '\0') { exit(EXIT_FAILURE); }

        char** a_temp = split_string(readline());

        int a[n];

        for (int a_itr = 0; a_itr < n; a_itr++) {
            char* a_item_endptr;
            char* a_item_str = a_temp[a_itr];
            int a_item = strtol(a_item_str, &a_item_endptr, 10);

            if (a_item_endptr == a_item_str || *a_item_endptr != '\0') { exit(EXIT_FAILURE); }

            a[a_itr] = a_item;
        }

        char** b_temp = split_string(readline());

        int b[m];

        for (int b_itr = 0; b_itr < m; b_itr++) {
            char* b_item_endptr;
            char* b_item_str = b_temp[b_itr];
            int b_item = strtol(b_item_str, &b_item_endptr, 10);

            if (b_item_endptr == b_item_str || *b_item_endptr != '\0') { exit(EXIT_FAILURE); }

            b[b_itr] = b_item;
        }

        int result = twoStacks(x, n, a, m, b);

        fprintf(fptr, "%d\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
