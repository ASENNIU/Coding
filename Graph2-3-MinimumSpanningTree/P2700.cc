//
// Created by 13345 on 2023/12/6.
//

#include <cstdio>
#include <algorithm>

#define MAXN 100005

struct edge{
    int u, v, w;
}edges[MAXN];

int cnt, n, k, fa[MAXN], u, v, w;
long long tot, ans;
bool occupy[MAXN];

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
    scanf("%d %d", &n, &k);
    for (unsigned i = 0; i < k; ++i) {
        scanf("%d", &u);
        occupy[u] = true;
//        printf("occupy %d, flag: %d\n", u, occupy[u]);
    }
    for (unsigned i = 1; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        ans += w;
    }
    for (int i = 0; i <= n; ++i) fa[i] = i;
    std::sort(edges, edges + cnt,
              [](const edge& a, const edge& b) {
                  return a.w > b.w;
    });
    for (unsigned i = 0; i < cnt; ++i) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        u = find(u);
        v = find(v);
        if (occupy[u] && occupy[v]) {
            continue;
        }
        fa[u] = v;
        ans -= w;
        if(occupy[u]) occupy[v] = true;
        else if (occupy[v]) occupy[u] = true;

    }
//    ans = tot -ans;
    printf("%lld\n", ans);
    return 0;
}