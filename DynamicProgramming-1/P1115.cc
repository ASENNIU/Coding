//
// Created by 13345 on 2023/12/12.
//

#include <cstdio>
#include <algorithm>

#define MAX_N 200005

int a[MAX_N], n, ans = -1e9;

int main()
{
    scanf("%d", &n);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i] = std::max(a[i], a[i-1] + a[i]);
        if (a[i] > ans) {
            ans = a[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}