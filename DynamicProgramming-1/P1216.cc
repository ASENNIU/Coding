//
// Created by 13345 on 2023/12/9.
//

#include <cstdio>
#include <algorithm>
#define N 1005

int a[N];
int tmp[N];

int main()
{
    int r;
    scanf("%d", &r);
    for (unsigned i = 1; i <= r; ++i) {
        for (unsigned j = 1; j <= i; ++j) {
            scanf("%d", tmp + j);
        }
        for (unsigned j = i; j >= 1; --j) {
            a[j] = std::max(tmp[j] + a[j - 1], tmp[j] + a[j]);
        }
    }
    int ans = 0;
    for (unsigned i = 1; i <= r; ++i) {
        if (a[i] > ans) ans = a[i];
    }

    printf("%d\n", ans);
    return 0;
}