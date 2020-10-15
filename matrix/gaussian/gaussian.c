#include <stdio.h>



void gauss(int m,int n,float matrix[m][n])
{
	for(int i = 0; i < m; i++)
	{
		if(i < n)
		{
		for(int j = i; j < n; j++)
		{
			matrix[i][j] /= matrix[i][i];
		}
		for(int w = 0; w < m; w++)
		{
			if (w != i)
			{
			float to_substract_factor = matrix[w][i]; 
			for(int v = 0; v < n; v++)
			{
				matrix[w][v] -= to_substract_factor*matrix[i][v];
				
			}
			}
		
		}
		}
		else
		{
		break;
		}
	}

}



int main()
{
	int m,n;
	scanf("%i %i\n",&m,&n);
	float matrix[m][n];
	for(int x=0;x<m;x++)
	{
		for(int y=0;y<n;y++)
		{
			scanf("%f",&matrix[x][y]);
		}
	}
	gauss(m,n,matrix);
	for(int x=0;x<m;x++)
	{
		for(int y=0;y<n;y++)
		{
			printf("%2.1f ",matrix[x][y]);
		}
		printf("\n");
	}

}
