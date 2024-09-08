#include <bits/stdc++.h>

#define MAXN 1000010

int a[MAXN];
int b[MAXN];


int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", a + i);
    }

    std::sort(a, a + n);
    int i = 0, j = n -1, idx = n - 1;
    while (i <= j) {
        b[i++] = a[idx--];
        if (idx < 0) break;
        b[j--] = a[idx--];
    }

    long long ans = 0;
    for (i = 0; i < n; ++i) {
        ans += (i + 1) * (n - i) * b[i];
    }

    printf("%lld\n", ans);

    return 0;
}