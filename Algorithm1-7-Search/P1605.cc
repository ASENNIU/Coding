//
// Created by 13345 on 2023/9/28.
//

#include <cstdio>

#define N 6

bool map[N][N];
bool vis[N][N];
int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};
int end_x, end_y;
int n, m, t, x, y;
int ans = 0;

void dfs(int cur_x, int cur_y);

int main()
{
    scanf("%d %d %d", &n, &m, &t);
    scanf("%d %d %d %d", &x, &y, &end_x, &end_y);
    int tmp_x, tmp_y;
    for (unsigned i = 0; i < t; ++i) {
        scanf("%d %d", &tmp_x, &tmp_y);
        map[tmp_x][tmp_y] = true;
    }
    vis[x][y] = true;
    dfs(x, y);

    printf("%d\n", ans);
    return 0;
}

void dfs(int cur_x, int cur_y) {
    if (cur_x == end_x && cur_y == end_y) {
        ++ans;
    }
    for (unsigned i = 0; i < 4; ++i) {
        int u = cur_x + dx[i];
        int v = cur_y + dy[i];
        if (u > 0 && u <= n && v > 0 && v <= m && !vis[u][v] && !map[u][v]) {
            vis[u][v] = true;
            dfs(u, v);
            vis[u][v] = false;
        }
    }
}