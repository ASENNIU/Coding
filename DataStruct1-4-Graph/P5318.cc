//
// Created by 13345 on 2023/11/14.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAXN 100005

std::vector<int> graph[MAXN];
bool vis[MAXN];
int n, m;

void dfs(int x, int visited) {
    vis[x] = true;
    printf("%d ", x);
    if (visited == n) {
        return;
    }
    for (unsigned i = 0; i < graph[x].size(); ++i) {
        if (!vis[graph[x][i]]) {
            dfs(graph[x][i], visited + 1);
        }
    }
}

void bfs(int x) {
    memset(vis, 0, MAXN);
    std::queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty() ) {
        int v = q.front();
        q.pop();
        vis[v] = true;
        printf("%d ", v);
        for (int u : graph[v]) {
            if (!vis[u]) {
                q.push(u);
                vis[u] = true;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int u, v;
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }
    for (unsigned i = 1; i <= n; ++i) {
        std::sort(graph[i].begin(), graph[i].end());
    }
    dfs(1, 0);
    printf("\n");
    bfs(1);

    return 0;
}