//
// Created by 13345 on 2023/11/14.
//

#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-48;
    return x*f;
}
int T,n,x;
unordered_map<int,bool>s;//定义
void work()
{
    s.clear();//清空
    n=read();
    For(i,1,n){
        x=read();
        if(!s[x]){//没有的话，直接输出+标记掉。
            printf("%d ",x);
            s[x]=1;
        }
    }puts("");//换行
}
int main()
{
    T=read();
    while(T--)work();
    return 0;
}