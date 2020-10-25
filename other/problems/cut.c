#include <stdio.h>
#include <stdlib.h>



int cut(int *a,int n){
	int *M,*m;
	M = (int*)malloc(sizeof(int)*n);
	m = (int*)malloc(sizeof(int)*n);
	M[0] = a[0];
	m[n-1] = a[n-1];
	for(int x = 1; x < n; x++){
		M[x] = (a[x] < M[x-1])? M[x-1] : a[x];
		m[n-x-1] = (a[n-x-1] < m[n-x])? a[n-x-1] : m[n-x];
	}
	int res = -1;
	for(int x = 0; x < n; x++){
		if(M[x] <= m[x]){
			res = x;
			return res;
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	int n,res;
	int *arr;
	scanf("%i",&n);
	arr = (int*)malloc(sizeof(int)*n);
	for(int x = 0; x < n; x++){
		scanf("%i",&arr[x]);
	}
	res = cut(arr,n);
	printf("%i\n",res);
	free(arr);
	return 0;
}