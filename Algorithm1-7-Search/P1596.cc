//
// Created by 13345 on 2023/10/3.
//

/***
 * 并查集，求连通图是个好东西
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=105;
int n,m,f[10005],ans;//f是并查集数组（并为一维），ans是水坑个数
char p[maxn][maxn];
int fa(int x){//简单的寻找祖先，又名找爸爸
    if(f[x]==x)return x;
    return fa(f[x]);
}
void hebing(int x,int y){//合并祖先
    int fx=fa(x),fy=fa(y);
    if(fx==x){
        f[x]=fy;
        return;
    }
    f[fy]=fx;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        getchar();//读掉换行符
        for(int j=1;j<=m;++j){
            scanf("%c",&p[i][j]);
            f[(i-1)*m+j]=(i-1)*m+j;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(p[i][j]=='W'){//如果本身有积水
                int pp=(i-1)*m+j;
                if(p[i][j+1]=='W')hebing(pp,pp+1);//正右方向
                if(p[i+1][j-1]=='W')hebing(pp,pp+m-1);//左下方向
                if(p[i+1][j]=='W')hebing(pp,pp+m);//正下方
                if(p[i+1][j+1]=='W')hebing(pp,pp+m+1);//右下方向
            }
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(p[i][j]=='W')//如果本身有积水且祖先为自己本身，则视为一个新的水坑
                ans+=(f[(i-1)*m+j]==(i-1)*m+j);
    printf("%d",ans);
    return 0;
}