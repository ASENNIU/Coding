//
// Created by 13345 on 2023/12/12.
//

#include <cstdio>

#define MAX_V 20005
#define MAX_N 35

int a[MAX_N], n, v;
bool dp[MAX_V];

int main()
{
    scanf("%d", &v);
    scanf("%d", &n);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    dp[0] = true;
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = v; j >= a[i]; --j) {
            dp[j] |= dp[j-a[i]];
        }
    }
    int ans = 0;
    for (int i = v; i >= 0; --i) {
        if (dp[i]) {
            ans = i;
            break;
        }
    }
    printf("%d", v - ans);
    return 0;
}

