#include"stdio.h"
#include"string.h"

#define N 10001
int main(){
	int t;
	int i,j,lt;
	char fenshen[N],lfenshen;
	int calpha[26],cnum[10],phone[10];
	scanf("%d",&t);
	for(lt=0;lt<t;lt++){
		scanf("%s",fenshen);
		lfenshen = strlen(fenshen);
		for(i=0;i<26;i++)
			calpha[i] = 0;
		for(i=0;i<lfenshen;i++){
			calpha[fenshen[i]-'A'] ++;
		}
		
		
		
		cnum[2] = calpha['W'-'A']; calpha['O'-'A']-=cnum[2];
		cnum[6] = calpha['X'-'A']; calpha['S'-'A'] -= cnum[6]; calpha['I'-'A']-=cnum[6];
		cnum[4] = calpha['U'-'A']; calpha['O'- 'A'] -= cnum[4]; calpha['F'-'A']-=cnum[4];
		cnum[8] = calpha['G'-'A']; calpha['H'-'A'] -= cnum[8]; calpha['I'-'A']-=cnum[8];
		cnum[0] = calpha['Z'-'A']; calpha['O'-'A'] -= cnum[0];
		cnum[1] = calpha['O'-'A'];
		cnum[3] = calpha['H'-'A'];
		cnum[5] = calpha['F'-'A'];  calpha['I'-'A']-=cnum[5];
		cnum[7] = calpha['S'-'A'];
		cnum[9] = calpha['I'-'A']; 
		
		for(i=0;i<10;i++)
			phone[i] = cnum[(i+8)%10];
		for(i=0;i<10;i++){
			for(j=0;j<phone[i];j++)
				printf("%d",i);
		} 
		printf("\n");
	}
	return 0;
} 
