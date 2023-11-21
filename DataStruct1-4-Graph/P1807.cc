//
// Created by 13345 on 2023/11/21.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 1505

std::vector<int> edges[MAXN], weights[MAXN];
int ind[MAXN], d[MAXN];

int main()
{
    int n, m, u, v, w;
    std::queue<int> q;
    scanf("%d %d", &n, &m);
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back(v);
        weights[u].push_back(w);
        ++ind[v];
    }

    for (int i = 2; i <= n; ++i) {
        d[i] = -1e9;
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    // 过滤其他入度为0的点
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u == n) {
            printf("-1\n");
            return 0;
        }
        for (unsigned i = 0; i < edges[u].size(); ++i) {
            v = edges[u][i];
            if (--ind[v] == 0) {
                q.push(v);
            }

        }
    }

    q.push(1);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (unsigned i = 0; i < edges[u].size(); ++i) {
            v = edges[u][i];
            if (--ind[v] == 0) {
                q.push(v);
            }
            if (d[v] < d[u] + weights[u][i]) {
                d[v] = d[u] + weights[u][i];
            }
        }
    }

    printf("%d\n", d[n]);

    return 0;
}