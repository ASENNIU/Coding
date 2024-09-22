#include <algorithm>
#include <cstdio>
#include <vector>

int f[305][305], s[305], n, m, degree[305];
std::vector<int> e[305];

int dfs1(int u) {
  int p = 1;
  f[u][1] = s[u];
  for (auto v : e[u]) {
    int siz = dfs1(v);
    for (int i = std::min(p, m + 1); i; --i) {
      for (int j = 1; j <= siz && i + j <= m + 1; ++j) {
        f[u][i + j] = std::max(f[u][i + j], f[u][i] + f[v][j]);
      }
    }
    p += siz;
  }
  return p;
}

void solve1() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d %d", &k, &s[i]);
    e[k].push_back(i);
  }
  dfs1(0);
  printf("%d\n", f[0][m + 1]);
}

int main() {
  solve1();
  return 0;
}