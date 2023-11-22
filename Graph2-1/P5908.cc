//
// Created by 13345 on 2023/11/22.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge{
    int v, nxt;
}e[200010];
int head[200010], cnt, n, d, x, y, vis[100010];
inline void add(int u, int v){
    e[++cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}//链式前向星建图
void dfs(int u){//求深度
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].v;
        if(vis[v]) continue;//已经遍历过就不遍历了
        vis[v] = vis[u] + 1;//深度+1
        dfs(v);//继续搜索
    }
    return;
}
int main(){
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n; ++i){
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);//注意是无向图
    }
    int ans = 0;
    dfs(vis[1] = 1);//压行QWQ
    for(int i = 2; i <= n; ++i) if(vis[i] - 1 <= d) ans++;//vis[i] - 1即为1到i的距离
    printf("%d", ans);
    return 0;
}