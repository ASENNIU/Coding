#include <algorithm>
#include <cstdio>

struct edge {
  int v, next;
}e[6005];

int head[6005], n, cnt, f[6005][2], ans, is_h[6005], vis[6005];

void addedge(int u, int v) {
  e[++cnt].v = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}

void calc(int k) {
  vis[k] = 1;
  for (int i = head[k]; i; i = e[i].next) {
    if (vis[e[i].v]) continue;
    calc(e[i].v);
    f[k][1] += f[e[i].v][0];
    f[k][0] += std::max(f[e[i].v][0], f[e[i].v][1]);
  }
  return;
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &f[i][1]);
  for (int i = 1; i < n; ++i) {
    int l, k;
    scanf("%d %d", &l, &k);
    is_h[l] = 1;
    addedge(k, l);
  }

  for (int i = 1; i <= n; ++i) {
    if (!is_h[i]) {
      calc(i);
      printf("%d\n", std::max(f[i][0], f[i][1]));
      return 0;
    }
  }

  return 0;
} 