//
// Created by 13345 on 2023/12/14.
//

#include <cstdio>
#include <algorithm>

#define MAX_N 105
#define MAX_M 10005

int a[MAX_N], dp[MAX_M];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    dp[0] = 1;
    for (unsigned i = 1; i <= n; ++i) {
        for(int j = m; j >= a[i]; --j) {
            dp[j] = dp[j] + dp[j-a[i]];
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}