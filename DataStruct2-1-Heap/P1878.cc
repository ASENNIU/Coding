//
// Created by 13345 on 2023/12/25.
//

#include<cctype>
#include<cstdio>
#include<queue>
#define rd read()
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=200005;
inline int read()
{
    int x=0;
    bool f=false;
    char g=getchar();
    for(;!isdigit(g);g=getchar())if(g=='-')f=true;
    for(;isdigit(g);g=getchar())x=(x<<3)+(x<<1)+(g^48);
    if(f)return -x;
    return x;
}//快读
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar((x%10)|48);
    return;
}//快写
inline int abs(int x){if(x>0)return x;return-x;}
struct note{
    int l,r,cha;
    friend bool operator < (note a,note A){
        if(a.cha==A.cha)
            return a.l > A.l;
        return a.cha > A.cha;
    }
};
priority_queue < note > que;
queue < note > ANS;
int n,ans=0;
int a[MAXN];
bool sex[MAXN];
bool danced[MAXN];
int L[MAXN],R[MAXN];
int main()
{
    n=rd;
    if(n==1){printf("0\n");return 0;}
    for(int i=1;i<=n;i++)
    {
        L[i]=i-1;R[i]=i+1;
        char g;
        while(!isalpha(g=getchar()));
        if(g=='G')sex[i]=true;
    }
    L[1]=INF;R[n]=INF;
    for(int i=1;i<=n;i++){
        a[i]=rd;
        if(i==1)continue;
        if(sex[i]^sex[i-1])//一男一女
            que.push((note){i-1,i,abs(a[i-1]-a[i])});
    }
    while(que.size()){
        note x=que.top();
        que.pop();
        if(danced[x.l]||danced[x.r])continue;
        danced[x.l]=true;danced[x.r]=true;
        ans++;
        ANS.push((note){x.l,x.r,0});
        if(R[x.r]!=INF)L[R[x.r]]=L[x.l];
        if(L[x.l]!=INF)R[L[x.l]]=R[x.r];
        if(R[x.r]!=INF&&L[x.l]!=INF)
            if(sex[R[x.r]]^sex[L[x.l]])//形成了一对新的相邻男女
                que.push((note){L[x.l],R[x.r],abs(a[L[x.l]]-a[R[x.r]])});
    }
    write(ans);
    putchar('\n');
    while(ANS.size()){
        printf("%d %d\n",ANS.front().l,ANS.front().r);
        ANS.pop();
    }
    return 0;
}