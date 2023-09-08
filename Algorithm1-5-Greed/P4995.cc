//
// Created by 13345 on 2023/9/7.
//

#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 305
int a[N];

int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (unsigned i = 1;  i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n + 1);
    int left = 0, right = n;
    for (;left < right; ) {
        ans += std::pow(a[right] - a[left], 2);
        ++left;
        ans += std::pow(a[right] - a[left], 2);
        --right;

    }
    printf("%lld\n", ans);
    return 0;
}