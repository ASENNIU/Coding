#include <cstdio>
#include <algorithm>

#define  MAXN 105

struct edge{
    int to, pre;
}edges[MAXN];

int head[MAXN], cur, depth[MAXN], father[MAXN], width[MAXN];

void add(int u , int v) {
    edges[++cur].to = v;
    edges[cur].pre = head[u];
    head[u] = cur;
}

void dfs(int x, int fa) {
    father[x] = fa;
    depth[x] = depth[fa] + 1;
    for (int i = head[x]; i; i =edges[i].pre) {
        if (edges[i].to != fa) {
//            printf("dfs go into: %d\n", edges[i].to);
            dfs(edges[i].to, x);
        }
    }
}

int get_lca(int x, int y) {
    while (x != y) {
        if (depth[x] > depth[y]) {
            x = father[x];
        } else {
            y = father[y];
        }
    }
    return x;
}


int main()
{
    int n, u, v;
    scanf("%d", &n);
    for (unsigned i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        add(u, v);
    }
    scanf("%d %d", &u, &v);
    dfs(1, 0);
//    printf("finish dfs\n");
    int dep = 0, wid = 0;
    for (int i = 1; i <=n; ++i) {
        width[depth[i]]++;
        dep = std::max(dep, depth[i]);
    }
    for (int i = 1; i <= dep; ++i) {
        wid = std::max(wid, width[i]);
    }

    int a = get_lca(u, v);
    int dist = (depth[u] - depth[a]) * 2 + (depth[v] - depth[a]);

    printf("%d\n%d\n%d\n", dep, wid, dist);

    return 0;
}