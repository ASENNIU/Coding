// 米小游和流莹到达了一个被红色海洋包裹着的星球，星球上有一些陆地，
// 流萤准备点燃其中一片大海。具体来说，就是在一张二维地图上，分成了n*m
// 个格子，每个格子的类型要么是大海，要么是陆地。若相邻（通过格子的边相邻）
// 两个格子的类型相同，则视为同一个连通块。大海被点燃后会变成陆地，
// 点燃一片大海就是把一个大海连通块变成一个陆地连通块。米小游想知道在流萤
// 最多点燃一片大海后，最大陆地连通块大小的最大值是多少。

#include <bits/stdc++.h>

#define MAXN 5000

int n, m, curLandId = 0;
char map[MAXN][MAXN];
int landId[MAXN][MAXN];
int landSize[MAXN * MAXN];
bool vis[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(int x, int y);
int dfs(int x, int y, int id);
int igniteSeaBlock(int x, int);

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf(" %c", &map[i][j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == '#' && landId[i][j] == 0) {
        ++curLandId;
        landSize[curLandId] = dfs(i, j, curLandId);
      }
    }
  }

  int maxLandSize = *std::max_element(landSize, landSize + curLandId + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j] == '.' && !vis[i][j]) {
        int newSize = igniteSeaBlock(i, j);
        maxLandSize = std::max(maxLandSize, newSize);
      }
    }
  }

  printf("%d\n", maxLandSize);

  return 0;
}

bool check(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}


int dfs(int x, int y, int id) {
  std::stack<std::pair<int, int>> st;
  st.emplace(x, y);
  landId[x][y] = id;
  int size = 0;

  while (!st.empty()) {
    auto cur = st.top();
    st.pop();
    ++size;
    int cx = cur.first, cy = cur.second;
    for (int i = 0; i < 4; ++i) {
      int u = cx + dx[i], v = cy + dy[i];
      if (check(u, v) && map[u][v] == '#' && !landId[u][v]) {
        st.emplace(u, v);
        landId[u][v] = id;
      }
    }
  } 

  return size;
}

int igniteSeaBlock(int x, int y) {
  std::queue<std::pair<int, int>> q;
  q.emplace(x, y);
  vis[x][y] = true;
  int size = 0;
  std::set<int> adjcentLand;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    ++size;
    int cx = cur.first, cy = cur.second;
    for (int i = 0; i < 4; ++i) {
      int u = cx + dx[i], v = cy + dy[i];
      if (check(u, v) && map[u][v] == '.' && !vis[u][v]) {
        vis[u][v] = true;
        q.emplace(u, v);
      }
      if (check(u, v) && map[u][v] == '#') {
        int id = landId[u][v];
        if (adjcentLand.find(id) == adjcentLand.end()) {
          size += landSize[id];
          adjcentLand.insert(id);
        }
      }
    }
  }

  return size;
}
