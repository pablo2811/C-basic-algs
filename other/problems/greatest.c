#include <stdio.h>

void greatest(int a[],int n,int b[],int m)
{
	for(int x = 0; x < m;x++){
		b[x] = 0;
	}
	for(int x = 0; x < n;x++){
		if(a[x] < m){
			for(int j = a[x];j < m;j++){
				b[j] += 1;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%i %i",&n, &m);
	int c[n],x[m];  
	for(int x = 0 ;x < n; x++){
		scanf("%i",&c[x]);
	}
	greatest(c,n,x,m);
	for(int z = 0; z < m; z++){
		printf("%i ",x[z]);
	}
	printf("\n");
	return 0;
}