#include <stdio.h>

// given increasing seq A and decreasing seq B find if E(i,j) such 
// sum(A[i]....A[j]) == sum(B[i]......B[j])
// naive alg - O(n^3)
// here O(n^2) optimized alg.

int segments(int A[], int B[],int n)
{
	int sum_A[n],sum_B[n];
	*sum_A = *sum_B = 0;
	for(int x = 1; x < n; x++){
		sum_A[x] = sum_A[x-1] + A[x];
		sum_B[x] = sum_B[x-1] + B[x];
	}
	for(int L = 1; L < n; L++){
		int left = 0;
		int right = left + L;
		while(right < n && (sum_A[right] - sum_A[left]) < (sum_B[right] - sum_B[left])){
			right++;
			left++;
		}
		if((sum_A[right] - sum_A[left]) == (sum_B[right] - sum_B[left])){
			return 1;
		}
	}
	return 0;

}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%i",&n);
	int A[n],B[n];
	for(int x = 0; x < n; x++){
		scanf("%i",&A[x]);
	}
	for(int x = 0; x < n; x++){
		scanf("%i",&B[x]);
	}
	printf("%i\n", segments(A,B,n));
	return 0;
}