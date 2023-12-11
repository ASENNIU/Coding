//
// Created by 13345 on 2023/12/11.
//

#include <cstdio>

#define MAX_N 25

int a[MAX_N], dp[MAX_N], g[MAX_N][MAX_N], pre[MAX_N], n, ans, t;

void print(int t) {
    if (t == 0) return;
    print(pre[t]);
    printf("%d ", t);
}

int main()
{
    scanf("%d", &n);
    for (unsigned i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (unsigned i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            scanf("%d", &g[i][j]);
        }
    }

    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j < i; ++j) {
            if (g[j][i] && dp[j] > dp[i]) {
                dp[i] = dp[j];
                pre[i] = j;
            }
        }
        dp[i] += a[i];
        if (dp[i] > ans) {
            ans = dp[i];
            t = i;
        }
    }
    print(t);
    printf("\n%d\n", ans);

    return 0;
}
