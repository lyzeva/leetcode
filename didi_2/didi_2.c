Ö»Í¨¹ý80% 
#include<stdio.h>
#include<stdlib.h>
#define N 1001 
#define min(a,b) (a<b?a:b) 

int comp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
} 

int main(){
	int n,sum;
	int A[N];
	
	int i,j;
	
	int bucket[N] = {0}, lb = 0, left; 
	
	scanf("%d %d",&n, &sum);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	qsort(A,n,sizeof(int),comp);
	
	bucket[0] = 1; 
	left = A[0];
	for(i = 0; i<n && A[i]<= sum; i++){
		
		for(j=min(lb,sum-A[i]); j>=left; j--){
			if(bucket[j] != 0){
				bucket[j+A[i]] += bucket[j];
			}
		}
		bucket[A[i]]++;
		lb = lb+A[i];
	} 
	printf("%d",bucket[sum]);
	return 0;
}

/*
5 15
5 5 10 2 3
*/ 
