//
// Created by 13345 on 2023/9/19.
//

#include <stdio.h>

#define N 1000005

int trees[N];

int accumulate(int hight, int n);

int main()
{
    int n, m;
    int right = 2 * 1e9, left = 0, mid = (right + left) >> 1;
    scanf("%d %d", &n, &m);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", trees + i);
    }

    while (left < right) {
        long long get = accumulate(mid, n);
        if(get >= m) {
            left = mid + 1;
        } else {
            right = mid;
        }
        mid = (right + left) >> 1;
    }
    printf("%d\n", left -1);
    return 0;
}

int accumulate(int high, int n) {
    long long get = 0;
    for (unsigned i = 0; i < n; ++i) {
        if (trees[i] > high) {
            get += trees[i] - high;
        }
    }

    return get;
}