//
// Created by 13345 on 2023/12/11.
//

#include <cstdio>
#include <algorithm>

#define MAX_N 105

int dx[4]{0, 0, -1, 1};
int dy[4]{-1, 1, 0, 0};
int map[MAX_N][MAX_N], dp[MAX_N][MAX_N], n, m, ans;

int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (unsigned i = 0; i < 4; ++i) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u > 0 && u <= n && v > 0 && v <= m && map[u][v] < map[x][y]) {
            dp[x][y] = std::max(dp[x][y], dfs(u, v) + 1);
        }
    }

    return dp[x][y];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j <= m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j <= m; ++j) {
            ans = std::max(ans, dfs(i, j));
        }
    }

    printf("%d\n", ans);
    return 0;
}