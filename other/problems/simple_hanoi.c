#include <stdio.h>
#include <time.h>


void hanoi(int N, int n,int src,int help,int dest,int h[3][N]){
	if(!n){
		return;
	}
	hanoi(N,n-1,src,dest,help,h);
	h[dest][N - n] = h[src][N-n];
	h[src][N-n] = 0;
	hanoi(N,n-1,help,src,dest,h);

}

void print_vert(int n, int h[3][n]){
	for(int i = n-1; i >-1; i--){
		for(int j = 0; j < 3;j++){
			printf("%i ",h[j][i]);
		}
		printf("\n");
	}
}



int main(int argc, char const *argv[])
{
	int N;
	scanf("%i",&N);
	float times[N];
	FILE *fp;
	fp = fopen("C_hanoi_times","w");
	for(int i = 1; i <= N;i++){
		int tab[3][i];
		for(int x = 0; x < i;x++){
		tab[0][x] = i - x;
		tab[1][x] = 0;
		tab[2][x] = 0;
	}
	clock_t start = clock();
	hanoi(i,i,0,1,2,tab);
	clock_t end = clock();
	times[i-1] = (float)(end - start) / CLOCKS_PER_SEC;
	fprintf(fp,"%.5f\n",times[i-1]);
	
	}
	fclose(fp);
	
	
	// print_vert(N,tab)
	// print_vert(N,tab);
	return 0;
}