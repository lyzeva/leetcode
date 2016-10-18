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
试题二、选举问题
举行投票选举，有多个候选人得到投票。得到超过 1/k 总票数的候选
人当选（假设一定有且只有一个候选人能得到超过 1/k 的总票数）。
输入数组 data 中， data[i]为第 i 张选票的候选人序号（用 int 表示），
输出当选人的序号。
函数声明如下 int ChooseCandidate(vector<int> &data, int k);
*/
