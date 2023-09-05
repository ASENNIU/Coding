//
// Created by 13345 on 2023/9/5.
//

#include <cstdio>

long long a[100005];
long long ans;

int main()
{
    long long n, x, tmp;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if (a[i] + a[i - 1] > x) {
            tmp = a[i] + a[i - 1] - x;
            ans += tmp;
            a[i] -= tmp;
        }
    }
    printf("%lld\n", ans);
    return 0;
}