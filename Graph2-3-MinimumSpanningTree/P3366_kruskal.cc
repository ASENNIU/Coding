//
// Created by 13345 on 2023/12/3.
//

#include <cstdio>
#include <algorithm>

#define MAXN 5005
#define MAXM 200005

struct edge{
    int u, v, w;
}edges[MAXM];

int n, m, ans, u, v, w, cnt, fa[MAXN];

int ask(int x) {
    int r = x;
    while (fa[x] != x)
        x = fa[x];

    while (fa[r] != x) {
        int tmp = fa[r];
        fa[r] = x;
        r = tmp;
    }

    return x;
}

void add(int u , int v) {
    fa[ask(u)] = ask(v);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i){
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    std::sort(edges, edges + m, [](const edge& a, const edge& b) {return a.w < b.w; });
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (ask(u) != ask(v)) {
            add(u, v);
            ans += w;
            ++cnt;
        }
    }
    if (cnt != n - 1) {
        printf("orz\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}