//
// Created by 13345 on 2023/12/15.
//

#include <cstdio>
#include <algorithm>

#define MAX_N 105
#define MOD 1000007

int a[MAX_N], dp[MAX_N], sum[MAX_N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    dp[0] = 1;
    for (unsigned i = 0; i <= m; ++i) sum[i] = 1;
    for (unsigned i = 1; i <= n; ++i) {
        for (int j = m; j > 0; --j) {
//            for (int k = 1; k <= std::min(a[i], j); ++k) {
//              dp[j] = (dp[j] + dp[j - k]) % MOD;
//            }
            if (j - std::min(a[i], j) - 1 < 0) {
                dp[j] = (dp[j] + sum[j-1]) % MOD;
            } else {
                dp[j] = (dp[j] + sum[j-1] - sum[j - std::min(a[i], j) - 1] + MOD) % MOD;
            }
        }
        for (int j = 1; j <= m; ++j) {
            sum[j] = (sum[j - 1] + dp[j]) % MOD;
        }
    }
    printf("%d\n", dp[m]);

    return 0;
}