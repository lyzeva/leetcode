#include<stdio.h>
#define N 32 

char digits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main(){
	int m,n;
	
	char output[N];
	int sgn;
	int i=0;
 
	scanf("%d %d",&m,&n);
	
	if(m<0){
	 	sgn = -1;
	 	m *= sgn;
	}
	else if(m == 0){
		printf("0");
		return 0; 
	} 
	else
		sgn = 1;
		
	while(m!=0){
		output[i++] = digits[m%n];
		m /= n; 
	}
	if(sgn == -1)
		printf("-");
	for(i = i-1;i>=0;i--)
		printf("%c", output[i]);
	return 0;
} 
