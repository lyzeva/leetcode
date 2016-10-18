#include<iostream>
#include<vector>

using namespace std;

int ChooseCandidate(vector<int> &data, int k); 

int main(){
	int n,k,tmp;
	vector<int> data;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>tmp;
		data.push_back(tmp);
	} 
	cout<<ChooseCandidate(data,k)<<endl;
	return 0; 
} 

int ChooseCandidate(vector<int> &data, int k){
	int vote_num = data.size();
	int thresh = vote_num/k;
	for(int i=0; i<vote_num; i++){
		if(data[i]>0){
			int tmp1 = data[i],tmp2;
			data[i] = 0;
			while(data[tmp1]>0){
				tmp2 = data[tmp1];
				data[tmp1] = -1;
				tmp1 = tmp2;
			}
			data[tmp1] --;
			if(data[tmp1]*-1>thresh)
				return tmp1;
		}
	}
		
}
/*
�������ѡ������
����ͶƱѡ�٣��ж����ѡ�˵õ�ͶƱ���õ����� 1/k ��Ʊ���ĺ�ѡ
�˵�ѡ������һ������ֻ��һ����ѡ���ܵõ����� 1/k ����Ʊ������
�������� data �У� data[i]Ϊ�� i ��ѡƱ�ĺ�ѡ����ţ��� int ��ʾ����
�����ѡ�˵���š�
������������ int ChooseCandidate(vector<int> &data, int k);
*/
