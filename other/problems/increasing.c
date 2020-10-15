#include <stdio.h>

// find number of increasing of length 3, subsequences of C (which only consists of {0,1,2})



int increasing_sub(int c[],int size)
{
	int zeros[size],twos[size];
	if(!c[0]){
		zeros[0] = 1;
	}else{
		zeros[0] = 0;
	}
	if(c[size-1] == 2){
		twos[size-1] = 1;
	}else{
		twos[size-1] = 0;
	}
	for(int x = 1; x < size;x++){
		zeros[x] = zeros[x-1];
		twos[size-x-1] = twos[size-x];
		if(!c[x]){
			zeros[x]++;
		}
		if(c[x] == 2){
			twos[size-x-1]++;
		}
	}
	int res = 0;
	for(int j = 0; j <size;j++){
		if(c[j] == 1){
			res += zeros[j]*twos[j];
		}

	}
	return(res);
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%i",&n);
	int c[n];  
	for(int x = 0 ;x < n; x++){
		scanf("%i",&c[x]);
	}
	printf("%i\n",increasing_sub(c,n));
	return 0;
}