#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int ChooseHorse(vector<int> &A, vector<int> &B);

int main(){
	vector<int> A;
	vector<int> B;
	int na,nb;
	int a;
	cin>>na>>nb;
	for(int i=0;i<na;i++){
		cin>>a;
		A.push_back(a); 
	} 
	for(int i=0; i<nb; i++){
		cin>>a;
		B.push_back(a); 
	} 
	cout<<ChooseHorse(A,B)<<endl; 
	return 0;
}



int ChooseHorse(vector<int> &A, vector<int> &B){
	int i=0, j=0;
	int mindiff;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	mindiff = B[0] - A[0];
	while( i<A.size()-1 && j<B.size()-1){
		while(i+1<A.size() && j<B.size() && A[i+1]<B[j]){
			i++;
		} 
		if(A[i+1] == B[j]) 
			return 0;
		if(abs(A[i]-B[j]) < mindiff)
			mindiff = abs(A[i]-B[j]);
		i++;
		if(abs(A[i]-B[j]) < mindiff)
			mindiff = abs(A[i]-B[j]);

		while(i<A.size() && j+1<B.size() && B[j+1]<A[i]){
			j++;
		} 
		if(A[i] == B[j+1])
			return 0;
		if(abs(A[i]-B[j])< mindiff)
			mindiff = abs(A[i]-B[j]);
		j++;
		if(abs(A[i]-B[j])< mindiff)
			mindiff = abs(A[i]-B[j]);
	}
	while( i+1<A.size() && j>B.size() && A[i+1]<B[j]){
		i++;
	}
	if(A[i+1] == B[j]) 
		return 0;
	if(abs(A[i]-B[j]) < mindiff)
		mindiff = abs(A[i]-B[j]);
	i++;
	if(abs(A[i]-B[j]) < mindiff)
		mindiff = abs(A[i]-B[j]);
	return mindiff;
}

/*
试题一、选马问题
有两组马 A 和 B，每一组都有很多马。假设所有的马跑的速度都是匀
速，请从两组马中选出跑步速度最接近的两匹马。
输入数组 A 和 B，其中 A[i]和 B[j]分别是 A 组第 i 匹和 B 组第 j 匹的速
度，输出速度差最小的两匹马之间的速度差值。
函数声明如下 int ChooseHorse(vector<int> &A, vector<int> &B);
PS：尽量使用比 O(N^2)复杂度更好的方法。
*/
