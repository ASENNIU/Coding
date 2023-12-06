//
// Created by 13345 on 2023/12/6.
//

#include <cstdio>
#include <algorithm>

#define MAXN 305

struct edge{
    int u, v, w;
}edges[MAXN * MAXN / 2 + MAXN];

int fa[MAXN], cnt, n, u, v, w, ans;

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

void combine(int u, int v) {
    fa[find(u)] = find(v);
}

int main()
{

    scanf("%d", &n);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", &w);
        add(0, i, w);
        fa[i] = i;
    }
    for (unsigned i = 1; i < n; ++i) {
        for (unsigned j = 1; j <= n; ++j){
            scanf("%d", &w);
            if (i < j) {
                add(i, j, w);
            }
        }
    }

    std::sort(edges, edges + cnt,
              [](const edge& a, const edge& b) {
                  return a.w < b.w;
    });
    for (unsigned i = 0; i < cnt; ++i) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (find(u) != find(v)) {
            ans += w;
            combine(u, v);
        }
    }

    printf("%d\n", ans);
    return 0;
}