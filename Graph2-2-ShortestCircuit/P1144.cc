//
// Created by 13345 on 2023/12/2.
//

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
#include <vector>

#define MAXN 1000005
#define MAXM 2000005
#define INF 0x3f3f3f3f
#define MOD 100003

struct edge{
    int to, pre;
}edges[MAXM];

int head[MAXN], d[MAXN], ans[MAXN], cnt;
bool vis[MAXN];
int n, m, u, v;

void bfs();
void spfa();
void dijkstra();

void add(int u, int v) {
    edges[++cnt].to = v;
    edges[cnt].pre = head[u];
    head[u] = cnt;
 }

 int main()
 {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    // bfs
    // spfa();
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
     return 0;
 }

 void bfs() {
     std::queue<int> q;
     d[1] = 0;
     vis[1] = true;
     ans[1] = 1;
     q.push(1);
     while (!q.empty()) {
         u = q.front();
         q.pop();
         for (int i = head[u]; i; i = edges[i].pre) {
             v = edges[i].to;
             if (!vis[v]) {
                 d[v] = d[u] + 1;
                 vis[v] = true;
                 q.push(v);
             }
             if (d[v] == d[u] + 1) {
                 ans[v] = (ans[v] + ans[u]) % MOD;
             }
         }
     }
}

void spfa() {
    std::queue<int> q;
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    vis[1] = true;
    ans[1] = 1;
    q.push(1);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = edges[i].pre) {
            v = edges[i].to;
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                ans[v] = ans[u];
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            } else if (d[v] == d[u] + 1) {
                ans[v] = (ans[v] + ans[u]) % MOD;
            }
        }
    }
}

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    ans[1] = 1;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
//    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edges[i].pre) {
            v = edges[i].to;
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                ans[v] = ans[u];
                q.emplace(d[v], v);
            } else if (d[v] == d[u] + 1) {
                ans[v] = (ans[v] + ans[u]) % MOD;
            }
        }
    }
}