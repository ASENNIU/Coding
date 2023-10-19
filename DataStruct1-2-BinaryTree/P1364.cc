//
// Created by 13345 on 2023/10/19.
//
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
    e[++num].to = to;
    e[num].next = head[from];
    head[from] = num;
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