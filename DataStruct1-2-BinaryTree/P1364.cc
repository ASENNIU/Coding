//
// Created by 13345 on 2023/10/19.
//

/***
 * 建图的方式：边去记录上一条边的信息，节点数组记录最后一条边的编号
 * 树上DP，以任意节点开始假设为重心（标记为root），求dist，那么重心在转移时，距离的变化有两项
 * 1. old_root的子节点距离会减少，减少的部分是各个子节点的权重和，对一个子节点而言dist的变化 weight * depth -> weight * (depth - 1)
 * 2. new_root的父节点的距离会增加，增加的部分是父节点的权重和
 * 3. 通过树上前缀和size来记录以root为根的各级节点的权重和，size[root] - size[u]，就可以表示出节点u的父节点的权重和
 */
#include <cstdio>
#include <algorithm>

#define INF 0x3f3f3f3f
#define MAXN 10010

struct Edge{
    int next, to;
}e[MAXN << 1];

int head[MAXN], num, w[MAXN], n, size[MAXN];

long long ans = INF, f[MAXN];

inline void Add(int from, int to) {
    e[++num].to = to;   // 当前边指向的节点
    e[num].next = head[from]; // 当前边的起始节点的上一条边的编号
    head[from] = num; // 当前节点最后一条边的编号
}

void dfs(int u, int fa, int dep) {
    size[u] = w[u];
    for (int i = head[u]; i; i = e[i].next) {
        if (e[i].to != fa) {
            dfs(e[i].to, u, dep + 1);
            size[u] += size[e[i].to];
        }
    }
    f[1] += w[u] * dep;
}

void dp(int u, int fa){  //转移
    for(int i = head[u]; i; i = e[i].next)
        if(e[i].to != fa)
            f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2, dp(e[i].to, u);
    ans = std::min(ans, f[u]); //取最小值
}

int main()
{
    int a, b;
    ans *= ans;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", w + i, &a, &b);
        if (a) {
            Add(i, a);
            Add(a, i);
        }
        if (b) {
            Add(i, b);
            Add(b, i);
        }
    }
    dfs(1, 0, 0);
    dp(1, 0);

    printf("%lld\n", ans);
    return 0;
}