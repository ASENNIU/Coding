//
// Created by 13345 on 2023/11/21.
//

#include <cstdio>
#include <cstring>
#include <vector>

#define MAX_EDGE 10005
#define MAX_NODE 1005

struct edge{
    int to, pre;
}edges[MAX_EDGE];

std::vector<int> e[MAX_NODE];

int head[MAX_NODE], cnt;
int cow[MAX_NODE], vis[MAX_NODE];
bool flag[MAX_NODE];

void add(int u, int v) {
    edges[cnt].to = v;
    edges[cnt].pre = head[u];
    head[u] = cnt++;
}

void add_(int u, int v) {
    e[u].push_back(v);
}

void dfs_(int x) {
    vis[x]++;
    flag[x] = true;
    for (int i = 0; i < e[x].size(); ++i) {
        if (!flag[e[x][i]]) {
            dfs_(e[x][i]);
        }
    }
}

void dfs(int x) {
    vis[x]++;
    flag[x] = true;
    for (int i = head[x]; i; i = edges[i].pre) {
        int v = edges[i].to;
        if (!flag[v]) {
            dfs(v);
        }
    }
}

int main()
{
    int k, n, m, idx, u, v;
    scanf("%d %d %d", &k, &n, &m);
    for (unsigned i = 1; i <= k; ++i) {
        scanf("%d", &cow[i]);
    }

    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        add(u, v);
    }
    for (unsigned i = 1; i <= k; ++i) {

        memset(flag, 0, MAX_NODE);
        dfs(cow[i]);
    }

    int ans = 0;
    for (unsigned i = 1; i <= n; ++i) {
//        printf("place: %d, vis: %d\n", i, vis[i]);
        if (vis[i] == k) {
            ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}