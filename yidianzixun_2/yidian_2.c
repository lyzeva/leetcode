#include<stdio.h>
#include<math.h>
#define N 20

int n;
int k[N];
int min;

int search(unsigned state);
int harm(unsigned state);

int main(){
	
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&k[i]);
	printf("%d",(1<<n) -1); 
	printf("%d",search( (unsigned)((1<<n) -1)));
	return 0;
} 

int search(unsigned state){
	int i;
	unsigned e=7;
	int min,tmp,harmv;
	if(state == 0)
		return 0;
	min = harm(state)*n;
	for(i=0;i<n-2;i++){
		if((state&(~e)) != state){
			tmp = search(state & (~e));
			harmv = harm(state &(~e));
			if(min>tmp+harmv)
				min = tmp+harmv; 
		}
		e = e<<1; 
	}
	e = (1<<(n-1))+3;
		if(state&(~e) != state){
		tmp = search(state & (~e));
		harmv = harm(state &(~e));
		if(min>tmp+harmv)
			min = tmp+harmv; 
		}
	e = (3<<(n-2))+1;
		if(state&(~e) != state){
		tmp = search(state & (~e));
		harmv = harm(state &(~e));
		if(min>tmp+harmv)
			min = tmp+harmv; 
		}
	return min;
}

int harm(unsigned state){
	int i;
	int res=0;
	for(i=0;i<n&&state!=0;i++){
		if(state%2)
			res+=k[i];
		state /=2; 
	}
	return res;
}

/*
7
3 4 2 2 1 4 1
*/
