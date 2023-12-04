//
// Created by 13345 on 2023/12/4.
//

#include <cstdio>
#include <algorithm>

#define MAXN 505

struct edge{
    int u, v, w;
}edges[250005];

int fa[MAXN], cnt;

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

void join(int u, int v) {
    fa[find(u)] = find(v);
}

int main()
{
    int a, b, u, v, w, ans = 0, tot = 0;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= b; ++i) {
        for (int j = 1; j <= b; ++j) {
            scanf("%d", &w);
            if (w != 0 && i < j) {
                add(i, j, w);
            }
        }
    }
    for (int i = 1; i <= b; ++i) {
        add(0, i, a);
    }

    std::sort(edges, edges + cnt, [](const edge& e1, const edge& e2) { return e1.w < e2.w; });

    for (int i = 0; i <= b; ++i) fa[i] = i;

    for (int i = 0; i < cnt && tot < b; ++i) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (find(u) != find(v)) {
            join(u, v);
            ++tot;
            ans += w;
        }
    }

    printf("%d\n", ans);

    return 0;
}