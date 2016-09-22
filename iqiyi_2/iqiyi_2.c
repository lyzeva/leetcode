#include<stdio.h>
#include<string.h> 
#define max(a,b) (a>b?a:b)


#define N 100

int max;

int main(){
	char str1[N],str2[N];
	int ls1,ls2;
	int f[N][N];
	int i,j;
	
	scanf("%s %s",str1,str2);
	ls1 = strlen(str1);
	ls2 = strlen(str2);
	
	search(str1,str2,pos);
	return 0; 
} 

void search(char *str1,char *str2,int pos,int step){
	char *str3;
	int ls1,ls2;
	ls1 = strlen(str1);
	ls2 = strlen(str2);
	if(pos>=ls1||pos>=ls2){
		step = step + abs(ls1-ls2);
		if(step<min){
			step = min;
			return; 
		}
	}
	else{
		if(str1[pos] == str2[pos]){
			search(str1,str2,pos+1,step);
		}
		if(ls1>ls2){
		}
		if(ls1<ls2){
		}
		search()
	}
}
