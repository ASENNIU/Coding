//
// Created by 13345 on 2023/11/23.
//

#include <cstdio>

#define MAXN 50005

struct edge {
    int to, pre;
}edges[MAXN << 1];

int depth[MAXN], size[MAXN], head[MAXN], cnt, f[MAXN], n;

void add(int u, int v) {
    edges[++cnt].to = v;
    edges[cnt].pre = head[u];
    head[u] = cnt;
}

void dfs_init(int x) {
    size[x] = 1;
    for (int e = head[x]; e; e = edges[e].pre) {
        int v = edges[e].to;
        if (depth[v]) continue;
        depth[v] = depth[x] + 1;
        dfs_init(v);
        size[x] += size[v];
    }
}

void dfs_dp(int now, int fa) {
    f[now] = f[fa] + n - 2 * size[now];
    for (int e = head[now]; e; e = edges[e].pre) {
        int v = edges[e].to;
        if (v == fa) continue;
        dfs_dp(v, now);
    }
}

int main()
{
    int u, v, ans = 0;
    scanf("%d", &n);
    for (unsigned i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    depth[1] = 1;
    dfs_init(1);
    for (unsigned i = 1; i <= n; ++i) {
        ans += depth[i] - 1;
    }
    f[1] = ans;
    for (int e = head[1]; e; e = edges[e].pre) {
        int v = edges[e].to;
        dfs_dp(v, 1);
    }
    for (unsigned i = 2; i <= n; ++i) {
        if (f[i] < ans) {
            u = i;
            ans = f[i];
        }
    }

    printf("%d %d\n", u, ans);
    return 0;
}
