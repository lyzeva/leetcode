//#include <stdafx.h>

#include <iostream>

#include<vector>

using namespace std;

int main()

{

    //存放山的个数

    long long n;

    //缓存输入的每个山头的高度

    long long x;

    //存放各个山头的高度

    vector<int> mon;

    //能够观测到对方烽烟的岗哨对的数量

    long long sum=0;

     

     

    while(cin>>n)

    {

        for(int i=0;i<n;i++)//用来接收各个山顶的高度

        {

            cin>>x;

            mon.push_back(x);

        } 

        sum=n;

        //山峰i

        for(int i=0;i<n;i++)

        {

            //山峰j

            for(int j=(i+2)%n;j!=i;(j++)%n)

            {

                //判断i和j之间是否有比他俩高的山峰

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
