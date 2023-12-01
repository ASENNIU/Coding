//
// Created by 13345 on 2023/12/1.
//

#include<bits/stdc++.h>//万能头
using namespace std;
int n,m,ans=0;//计数器
int dis[101][101],a[10001];//距离数组及必经之路数组
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);//输入必经之路
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&dis[i][j]);//输入距离
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }//上文所提到的Floyd算法模板
    for(int i=2;i<=m;i++)
    {
        ans+=dis[a[i-1]][a[i]];//计数
    }
    printf("%d",ans);//输出计数器
    return 0;
}