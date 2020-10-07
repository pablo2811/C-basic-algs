#include <stdio.h>

void matrix_mul(int m,int n,int t,float m1[m][n],float m2[n][t])
{
	float res[m][t];
	for(int i = 0 ; i < m; i++)
	{
		for(int j = 0; j < t; j++)
		{
			int sum = 0;
			for(int k = 0; k < n; k++)
			{
				sum += m1[i][k]*m2[k][j];
			}
			res[i][j] = sum;
		}
	
	}
	for(int z = 0; z < m; z++)
		{
			for(int t = 0; t < n; t++)
			{
				printf("%.1f ",res[z][t]);
			}
			printf("\n");
		}
}


int main()
{
	int m,n;
	scanf("%i %i\n",&m,&n);
	float m1[m][n];
	for(int x=0;x<m;x++)
	{
		for(int y=0;y<n;y++)
		{
			scanf("%f",&m1[x][y]);
		}
	}

	int z,t;
	scanf("%i %i\n",&z,&t);
	float m2[z][t];
	for(int x=0;x<z;x++)
	{
		for(int y=0;y<t;y++)
		{
			scanf("%f",&m2[x][y]);
		}
	}
	if( z == n )
	{
		matrix_mul(m,n,t,m1,m2);
		
	}
	else	
	{
		printf("Dimensions problem.");
	}
	
}
