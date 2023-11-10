//
// Created by 13345 on 2023/11/10.
//
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string,int> mp;
int n;
int main()
{
    ios::sync_with_stdio(false); //流式I/O优化
    cin.tie(0); //同上
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a; //读入操作
        if(a==1)
        {
            string b;
            int c;
            cin>>b>>c;
            mp[b]=c; //插入与修改
            cout<<"OK"<<endl;
        }
        else if(a==2)
        {
            string b;
            cin>>b;
            if(mp.count(b)==0) //如果没有学生b
            {
                cout<<"Not found"<<endl;
                continue;
            }
            cout<<mp[b]<<endl; //否则输出b的成绩
        }
        else if(a==3)
        {
            string b;
            cin>>b;
            if(mp.count(b)==0) //如果没有学生b
            {
                cout<<"Not found"<<endl;
                continue;
            }
            mp.erase(mp.find(b)); //否则删除b
            cout<<"Deleted successfully"<<endl;
        }
        else if(a==4)
        {
            cout<<mp.size()<<endl; //输出mp的大小
        }
    }
    return 0;
}