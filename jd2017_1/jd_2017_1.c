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
			if(pairs[j][i]){
				pairnum ++;	
				printf("%d ",array[j]);
			}
		}while(array[j]<array[i]);
		j = indexOf(i+1, length);
		if(!pairs[i][j]){
			j = i;
			do{
				j = indexOf(j+1,length);
				pairs[i][j] = true;
				if(pairs[j][i]){
					pairnum ++;	
					printf("%d ",array[j]);
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
/*
8
7 3 4 2 8 5 6 1
7 3
7 4
7 8
3 4
4 2
4 8
2 8
8 5
8 6
5 6
6 1
6 7
1 7
 
*/
