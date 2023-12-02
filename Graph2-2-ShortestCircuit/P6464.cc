//
// Created by 13345 on 2023/12/2.
//

#include<bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        //建立双向边
        dp[u][v] = w;
        dp[v][u] = w;
    }
    //floyd 算法
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    //假设假设建立传送门的点对为（i，j）(默认j > i)，枚举减少的距离任意一个点对点（a, b）（这里默认b > a）距离为
    int ans = INF, res;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            res = 0;
            for (int a = 1; a < n; a++)
                for (int b = a + 1; b <= n; b++)
                    if (a != i || b != j)
                        res += min(dp[a][b], min(dp[a][i] + dp[j][b], dp[a][j] + dp[i][b]));
            ans = min(ans, res);
        }
    printf("%d\n", ans);
    return 0;
}