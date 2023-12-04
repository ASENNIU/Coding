//
// Created by 13345 on 2023/12/4.
//
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    int t;
}a[222222];//x到y的边拥挤度t
int father[222222],n,m,s,t;
inline int find(int xx)//并查集
{
    while(xx!=father[xx])
    {
        xx=father[xx];//找祖先
    }
    return xx;
}
inline void unionn(int xx,int yy)//连接
{
    father[yy]=xx;
}
inline bool cmp(node p,node q)
{
    return p.t<q.t;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<=222221;i++)
    {
        father[i]=i;//假定祖先是自己
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
    }
    sort(a+1,a+m+1,cmp);//拥挤度从小到大排序
    int tot=0,num=0;
    for(int i=1;i<=m;i++)
    {
        int cc=find(a[i].x),dd=find(a[i].y);
        unionn(cc,dd);
        if(find(s)==find(t))
        {
            printf("%d",a[i].t);
            return 0;
        }
    }
}