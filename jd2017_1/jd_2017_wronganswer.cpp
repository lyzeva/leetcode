//#include <stdafx.h>

#include <iostream>

#include<vector>

using namespace std;

int main()

{

    //���ɽ�ĸ���

    long long n;

    //���������ÿ��ɽͷ�ĸ߶�

    long long x;

    //��Ÿ���ɽͷ�ĸ߶�

    vector<int> mon;

    //�ܹ��۲⵽�Է����̵ĸ��ڶԵ�����

    long long sum=0;

     

     

    while(cin>>n)

    {

        for(int i=0;i<n;i++)//�������ո���ɽ���ĸ߶�

        {

            cin>>x;

            mon.push_back(x);

        } 

        sum=n;

        //ɽ��i

        for(int i=0;i<n;i++)

        {

            //ɽ��j

            for(int j=(i+2)%n;j!=i;(j++)%n)

            {

                //�ж�i��j֮���Ƿ��б������ߵ�ɽ��

                if((mon[(j-1+n)%n]<mon[i])&&(mon[(j-1+n)%n]<mon[j]))

                    sum=sum+1;

                else

                    break;

                 

            }

        }

        cout<<sum;

    }

    system("pause");

}
