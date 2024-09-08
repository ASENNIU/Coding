#include <bits/stdc++.h>

const int MAXN = 5005;



int a[MAXN][MAXN];
int vis[MAXN][MAXN];

int n, m;

// L R U D 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y) {
    if (vis[x][y]) {
        return vis[x][y];
    }
    vis[x][y] = 1;
    if (x > n || y > m || x <= 0 || y <= 0) {
        return vis[x][y] = -1;
    }
    int u = x + dx[a[x][y]];
    int v = y + dy[a[x][y]];
    vis[x][y] = dfs(u, v);
    return vis[x][y];
}

int main()
{
    scanf("%d %d", &n, &m);
    char c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 前面加一个空格符，跳过空格或者是回车符
            scanf(" %c", &c);
            switch (c)
            {
            case 'L':
                a[i][j] = 0;
                /* code */
                break;
            case 'R':
                a[i][j] = 1;
                break;
            case 'U':
                a[i][j] = 2;
                break;
            case 'D':
                a[i][j] = 3;
                break;
            default:
                break;
            }
        }
        // 长教训了，scanf读取字符时，需要将缓冲区清空
        // getchar();
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dfs(i, j) == 1) {
                printf("P: %d, %d\n", i, j);
                ++ans;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}