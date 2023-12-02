//
// Created by 13345 on 2023/12/2.
//

#include <iostream>

using namespace std;
int tag[10][10];
int d[10];
int p[1000];
int main()
{
    string a;
    int n;
    while(cin>>a>>n)
    {
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            tag[x][y]=1;
        }
        for(int k=1;k<=9;k++)
            for(int i=0;i<=9;i++)
                for(int j=1;j<=9;j++)
                    if(tag[i][k]&&tag[k][j]) tag[i][j]=1;//可以间接转化的数，并且注意这个i,j,k的排列。只有这种排列可以找到所有情况
        for(int i=0;i<10;i++)
        {
            tag[i][i]=1;
            for(int j=0;j<10;j++)
                if(tag[i][j])
                    d[i]++;
        }
        int z=0;
        p[0]=1;
        for(int i=0;a[i];i++)
        {
            z=0;
            int x=d[a[i]-'0'];
            //cout<<x<<endl;
            for(int i=0;i<500;i++)
            {
                p[i]=(p[i]*x+z);
                z=p[i]/10;
                p[i]%=10;
                //cout<<p[i];
            }
            //cout<<endl;
        }
        int i=500;
        while(p[i]==0) i--;
        for(;i>=0;i--)
        {
            cout<<p[i];
        }
        cout<<endl;
    }
}