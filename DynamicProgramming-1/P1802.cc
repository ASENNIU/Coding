//
// Created by 13345 on 2023/12/12.
//

#include <cstdio>
#include <algorithm>

#define MAX_N 1005

int dp[MAX_N], lose[MAX_N], win[MAX_N], cost[MAX_N], n, x;
long long ans;

int main()
{
    scanf("%d %d", &n, &x);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d %d %d", lose + i, win + i, cost + i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= 0; --j) {
            if (j < cost[i]) {
                dp[j] = dp[j] + lose[i];
            } else {
                dp[j] = std::max(dp[j-cost[i]] + win[i], dp[j] + lose[i]);
            }
            if (dp[j] > ans) ans = dp[j];
        }
    }
    printf("%lld\n", ans * 5);
    return 0;
}