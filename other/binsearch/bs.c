#include <stdio.h>

int binary_search(int tab[],int l,int r,int target)
{
	if(l == r){
		if(tab[l] == target){
			return l;
		}else{
			return -1;
		}
	}else{
		int mid = (l+r)/2;
		if(tab[mid] > target){
			return binary_search(tab,l,mid,target);
		}else if (tab[mid] == target){
			return mid;
		}else{
			return binary_search(tab,mid,r,target);
		}
	}
}

int main(int argc, char const *argv[])
{
	int tab[] = {-10,-4,1,4,6,12,18};
	int S = sizeof(tab)/sizeof(int);
	printf("%i\n",binary_search(tab,0,S,18));
	return 0;
}

