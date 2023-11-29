//
// Created by 13345 on 2023/11/29.
//

#include <cstdio>
#include <cstring>
#include <queue>

#define INF 0x3f3f3f3f
#define MAXN 2010
#define MAXM 3010

int n, m;
int cnt, head[MAXN];
struct edge{
    int to, weight, pre;
}edges[MAXM << 1];

int dis[MAXN], cnt_enqueue[MAXN];
bool vis[MAXN];
std::queue<int> q;

inline void add(int u, int v, int w) {
    edges[++cnt].to = v;
    edges[cnt].weight = w;
    edges[cnt].pre = head[u];
    head[u] = cnt;
}

void input() {
    scanf("%d %d", &n, &m);
    cnt = 0;
    memset(head, 0, sizeof(head));
    int u, v, w;
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        if (w >= 0)
            add(v, u, w);
    }
}

void clear_queue(std::queue<int>& que) {
    std::queue<int> tmp;
    std::swap(que, tmp);
}

void spfa() {
    memset(dis, INF, sizeof(dis));
    memset(cnt_enqueue, 0, sizeof(cnt_enqueue));
    memset(vis, 0, sizeof(vis));
    clear_queue(q);

    dis[1] = 0;
    vis[1] = true;
    q.push(1);

    int u, v, w;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = false;

        for (int i = head[u]; i; i = edges[i].pre) {
            v = edges[i].to;
            w = edges[i].weight;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    if (++cnt_enqueue[v] >= n) {
                        printf("YES\n");
                        return;
                    }
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    printf("NO\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        spfa();
    }

    return 0;
}