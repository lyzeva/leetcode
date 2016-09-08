#include<stdio.h>
#include<stdbool.h>

#define N 1000

int indexOf(int i,int length);

int main(){
	int length;
	int array[N];
	bool pairs[N][N]={false};
	int pairnum = 0;
	
	
	int i,j;
	scanf("%d",&length);
	for(i=0 ;i<length; i++){
		scanf("%d", &array[i]);
	}
	
	for(i=0; i<length; i++){
		j = i;
		printf("%d:",array[i]);
		do{
			j = indexOf(j-1,length);
			if(j == i)
				break;
			pairs[i][j] = true;
			printf("%d ",array[j]);
			if(pairs[j][i]){
				pairnum ++;	
			}
		}while(array[j]<array[i]);
		j = indexOf(i+1, length);
		if(!pairs[i][j]){
			j = i;
			do{
				j = indexOf(j+1,length);
				printf("%d ",array[j]);
				pairs[i][j] = true;
				if(pairs[j][i]){
					pairnum ++;	
				}
			}while(array[j]<array[i]);
		}
		printf("\n");
	}
	printf("%d",pairnum);
	return 0;
} 

int indexOf(int i,int length){
	if(i<0)
		return indexOf(i+length, length);
	else if(i>=length)
		return i%length;
	else
		return i;
}

//1 3 4
// 5 2
