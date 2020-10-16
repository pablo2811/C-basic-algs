#include <stdio.h>
#include <stdlib.h>

int min(int midB, int r);

// https://www.hackerrank.com/challenges/largest-rectangle/problem


// bulid a segment tree that allows us to answer quieries like :
// what is the index of smallest buliding between i and j? [in O(logN*logN)]

void util_bulid(int L,int R,int v,int *h,int *seg_tree){
    if(L == R){
        seg_tree[v] = L;
        return;
    }else{
        int mid = (L + R)/2;
        util_bulid(L,mid,2*v + 1,h,seg_tree);
        util_bulid(mid+1,R,2*v + 2,h,seg_tree);
        int ind_min = (h[seg_tree[2*v+1]] < h[seg_tree[2*v+2]]) ? seg_tree[2*v+1] : seg_tree[2*v+2];
        seg_tree[v] = ind_min;
    }

}


void bulid_segment_tree(int h_count,int *h,int *seg_tree){
    util_bulid(0,h_count-1,0,h,seg_tree);

}
int min(int midB, int r) {
    return (midB < r) ? midB : r;
}

int max_of_two(int x, int y)
{
    return (x > y) ? x : y;
}

// util to process the query, used for searching down the segment tree.
int ind_min_util(int L,int R,int bound_L,int bound_R,int v,int *seg_tree,int *h)
{

    if(L > R)
    {
        return -1;
    }
    if(bound_L == L && bound_R == R)
    {
        return seg_tree[v];
    }
    int mid_b = (bound_L+bound_R)/2;

    int x = ind_min_util(L,min(mid_b,R),bound_L,mid_b,2*v+1,seg_tree,h);
    int y = ind_min_util(max_of_two(mid_b+1,L),R,mid_b+1,bound_R,2*v+2,seg_tree,h);
    if(x != -1){
        if(y != -1){
            return (h[x] < h[y]) ? x : y;

        }else{
            return x;
        }
    }else{
        return y;
        // 4th case is (imo) impossible

    }

}


int ind_min(int i,int j,int *seg_tree,int n,int *h)
{
    return ind_min_util(i,j,0,n-1,0,seg_tree,h);
}


int max_of_three(int m, int n, int p)
{
    return max_of_two(max_of_two(m, n), p);
}


// Observation: we can divide the problem into 3 subproblems of 
// finding bigest poster (or area) to the left (and right) of the smallest bulding
// in given subsequence of buldings. Then, compare it to best solution without dividing. 
// time comp: O(logn*logn)
int rectSearch(int L, int R,int *h,int *seg,int n){
    if(L > R){
        return 0;
    }
    if(L == R){
        return h[L];
    }else{
        int ind = ind_min(L,R,seg,n,h);
        int val = h[ind]*(R-L+1);
        int leftie = rectSearch(L,ind-1,h,seg,n);
        int rightie = rectSearch(ind+1,R,h,seg,n);
        return(max_of_three(val,leftie,rightie));

    }

}



long largestRectangle(int h_count, int* h){
    int *seg_tree = (int *)malloc(sizeof(int)*(4*h_count));
    bulid_segment_tree(h_count,h,seg_tree);
    return rectSearch(0,h_count-1,h,seg_tree,h_count);



}



int main(int argc, char const *argv[])
{
    int n;
    scanf("%i",&n);
    int *h;
    h = (int*)malloc(n*sizeof(int));
    for(int x = 0; x < n; x++){
        scanf("%i",&h[x]);
    }
    printf("%li\n",largestRectangle(n,h));

    return 0;
}
