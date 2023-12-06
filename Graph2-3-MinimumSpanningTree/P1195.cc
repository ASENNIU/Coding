//
// Created by 13345 on 2023/12/6.
//

#include <cstdio>
#include <algorithm>

#define MAXM 10005
#define MAXN 1005

struct edge{
    int u, v, w;
}edges[MAXM];

int cnt, n, m, k, tot, u, v, w, ans;
int fa[MAXN];
bool root[MAXN];

void add(int u, int v, int w) {

    edges[cnt].u = u;
    edges[cnt].v = v;
    edges[cnt].w = w;
    ++cnt;
}

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void combine(int u , int v) {
    fa[find(u)] = find(v);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    int min_edge_num = n - k;
    if (m < min_edge_num) {
        printf("No Answer\n");

    }
    for (unsigned i = 1; i <= n; ++i) fa[i] = i;
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }

    std::sort(edges, edges + cnt,
              [](const edge& a, const edge& b) { return a.w < b.w; });

    for (unsigned i = 0; i < cnt && tot < min_edge_num; ++i) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (find(u) != find(v)) {
            combine(u, v);
            ans += w;
            ++tot;
        }
    }


    printf("%d\n", ans);

    return 0;
}