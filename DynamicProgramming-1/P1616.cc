//
// Created by 13345 on 2023/12/14.
//

#include <cstdio>
#include <algorithm>

#define MAX_N 10005
#define MAX_TIME 10000005

int cost[MAX_N], value[MAX_N];
long long dp[MAX_TIME];

int main()
{
    int t, m;
    scanf("%d %d", &t, &m);
    for (unsigned i = 1; i <= m; ++i) {
        scanf("%d %d", cost + i, value + i);
    }

    for (unsigned i = 1; i <= m; ++i) {
        for (int j = cost[i]; j <= t; ++j) {
            dp[j] = std::max(dp[j], dp[j-cost[i]] + value[i]);
        }
    }
    printf("%lld\n", dp[t]);
    return 0;
}