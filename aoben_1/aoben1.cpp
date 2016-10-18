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
����һ��ѡ������
�������� A �� B��ÿһ�鶼�кܶ����������е����ܵ��ٶȶ�����
�٣������������ѡ���ܲ��ٶ���ӽ�����ƥ��
�������� A �� B������ A[i]�� B[j]�ֱ��� A ��� i ƥ�� B ��� j ƥ����
�ȣ�����ٶȲ���С����ƥ��֮����ٶȲ�ֵ��
������������ int ChooseHorse(vector<int> &A, vector<int> &B);
PS������ʹ�ñ� O(N^2)���Ӷȸ��õķ�����
*/
