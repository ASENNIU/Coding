//
// Created by 13345 on 2023/11/27.
//

#include <cstdio>
#include <queue>

#define MAXN 100010
#define MAXM 500010

struct node{
    int dis, pos;
    bool operator < (const node& other) const {
        return other.dis < dis;
    }
};

struct edge {
    int to, pre, dis;
}edges[MAXM];

int head[MAXN], dis[MAXN], cnt;
bool vis[MAXN];
int n, m, s;
std::priority_queue<node> q;

inline void add(int u, int v, int d) {
    ++cnt;
    edges[cnt].dis = d;
    edges[cnt].to = v;
    edges[cnt].pre = head[u];
    head[u] = cnt;
}



void dijkstra()
{
    dis[s] = 0;
    q.push((node){0, s});
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos;
        int d = tmp.dis;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; i; i = edges[i].pre) {
            int y = edges[i].to;
            if (!vis[y] && dis[y] > d + edges[i].dis) {
                dis[y] = d + edges[i].dis;
                q.push((node){dis[y], y});
//                if (!vis[y]) {
//                    q.push((node){dis[y], y});
//                }
            }
        }
    }
}

int main()
{
    int u, v, w;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i<= n; ++i) dis[i] = 0x7fffffff;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    putchar('\n');
    return 0;
}

