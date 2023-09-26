//
// Created by 13345 on 2023/9/26.
//

#include <stdio.h>
#include <algorithm>
#include <cstring>
#define N 20
#define MAX_TIME 1200

int a[N];
int dp[MAX_TIME];
int s[4];

int main()
{
    int ans = 0;
    for (unsigned i = 0; i < 4; ++i) {
        scanf("%d", s + i);
    }
    for (unsigned i = 0; i < 4; ++i) {
        int sum_t = 0;
        for (unsigned j = 0; j < s[i]; ++j) {
            scanf("%d", a + j);
            sum_t += a[j];
        }

        memset(dp, 0, MAX_TIME);
        for (unsigned j = 0; j < s[i]; ++j) {
            for (int k = sum_t >> 1; k >= a[j]; --k) {
                dp[k] = std::max(dp[k], dp[k - a[j]] + a[j]);
            }
        }

        ans += sum_t - dp[sum_t >> 1];
    }

    printf("%d\n", ans);
    return 0;
}
