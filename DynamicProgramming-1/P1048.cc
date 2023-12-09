//
// Created by 13345 on 2023/12/9.
//

#include <cstdio>
#include <algorithm>

#define N 105
#define MAX_TIME 1005

int cost[N], value[N], dp[MAX_TIME];
int main()
{
    int t, m;
    scanf("%d %d", &t, &m);
    for (unsigned i = 1; i <= m; ++i) {
        scanf("%d %d", cost + i, value + i);
    }
    for (int j = 1; j <= m; ++j) {
//        printf("item %d, cost: %d, value: %d\n", j, cost[j], value[j]);
        for (int i = t; i >= cost[j]; --i) {
            dp[i] = std::max(dp[i], dp[i-cost[j]] + value[j]);
//            printf("dp[%d]: %d ", i, dp[i]);
        }
//        printf("\n");

    }

    printf("%d\n", dp[t]);
    return 0;
}
