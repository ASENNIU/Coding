//
// Created by 13345 on 2023/11/21.
//

#include <cstdio>
#include <vector>
#include <queue>

const int mod = 80112002;
const int MAXN = 5005;

std::vector<int> edges[MAXN];
int ind[MAXN], num[MAXN], outd[MAXN], ans;

int main()
{
    int n, m, u, v;
    std::queue<int> q;
    scanf("%d %d", &n, &m);
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        ++ind[v];
        ++outd[u];
        edges[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) {
            q.push(i);
            ++num[i];
        }
    }
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (unsigned i = 0; i < edges[u].size(); ++i) {
            v = edges[u][i];
            if (--ind[v] == 0) {
                q.push(v);
            }
            num[v] = (num[u] + num[v]) % mod;

        }
    }
    for (int i = 1; i <= n; ++i) {
        if (outd[i] == 0) {
            ans = (ans + num[i]) % mod;
        }
    }

    printf("%d\n", ans);
    return 0;
}