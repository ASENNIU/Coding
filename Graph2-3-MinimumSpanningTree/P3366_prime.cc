//
// Created by 13345 on 2023/12/2.
//

#include <queue>
#include <cstdio>
#include <cstring>
#include <cstring>

#define MAXN 5005
#define MAXM 200005


struct edge{
    int to, w, pre;
}edges[MAXM << 1];

// 数组d应用于prime算法，表示加入最小生成树的点集到未加入的点集之间的最小距离
int head[MAXN], d[MAXN], cnt, tot, n, m, u, v, w, ans;
bool f[MAXN];

void add(int u, int v, int w) {
    edges[++cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].pre = head[u];
    head[u] = cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.emplace(0, 1);

    while (!q.empty() && tot < n) {
        u = q.top().second;
        w = q.top().first;

        q.pop();
        if (!f[u]) {
            f[u] = true;
            ++tot;
            ans += d[u];
//            printf("node %d, weight %d join\n", u, w);
            for (int i = head[u]; i; i = edges[i].pre) {
                v = edges[i].to;
                w = edges[i].w;
                if (w < d[v]) {
                    d[v] = w;
                    q.emplace(w, v);
                }
            }
        }
    }

//    while (!q.empty()) {
//        u = q.top().second;
//        w = q.top().first;
//        printf("node %d, weight %d remain\n", u, w);
//        q.pop();
//    }

    for (int i = 1; i <= n; ++i){
        if (!f[i]) {
            printf("orz\n");
            return 0;
        }
    }

    printf("%d\n", ans);

    return 0;
}