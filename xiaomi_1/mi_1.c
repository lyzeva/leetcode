#include"stdio.h"
#define N 1000 

int main(){
	int node[N], paren[N], hparen[N]={0}, hchil[N]={0};
	int n;
	int i,j,a,b,tmp;
	int root,depth = 0;
	
	scanf("%d", &n);
	for(i=0;i<n-1;i++){
		scanf("%d %d",&a, &b);
		paren[b] = a;
		hparen[b] = 1;
		hchil[a] = 1;
	}
	for(i=0;i<n;i++){
		if(hchil[i] == 0){
			a = i;
			b = 1;
			while(hparen[a]){
				a = paren[a];
				b++;
			}
			if(b>depth)
				depth = b;
		}
	}
	printf("%d",depth);
	return 0;
} 
