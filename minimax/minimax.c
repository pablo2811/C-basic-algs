#include <stdio.h>
#include <math.h>

int minimax(int *start,int *end,int *maximizer,int game[])
{
	if(end == start)
	{	
		return(game[end]);
		// int M = 10000;
		// int m = -10000;
		// for(int x = start; x <= end; x++)
		// {
		// 	if(game[x] < m)
		// 	{
		// 		m = game[x];
		// 	}
		// 	if(game[x] > M)
		// 	{
		// 		M = game[x];
		// 	}
		// }
		// if(maximizer)
		// {
		// 	return(M);
		// }
		// else
		// {
		// 	return(m);
		// }
	}

	int middle = (end+1) / 2;
	if (middle){
		printf("%i\n",middle);
	}
	
	
	if(maximizer)
	{	
		int *p = &(middle-1)
		int a = minimax(&start,&p,0,game);
		int b = minimax(&middle,&end,0,game);
		if(a > b){
			return a;
		}
		else{
			return b;
		}
	}else{
		int a = minimax(&start,&p,1,game);
		int b = minimax(&middle,end,1,game);
		if(b > a){
			return a;
		}
		else{
			return b;
		}
	}
}




int main()
{
	int n,size;
	scanf("%i\n",&n);
	size = pow(2,n);
	int game[size];
	for(int x = 0; x < size; x++)
	{
		scanf("%i", &game[x]);
	}
	printf("%i\n",size);
	int res = minimax(0,size-1,1,game);
}