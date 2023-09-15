//
// Created by 13345 on 2023/9/15.
//
/***
 * 这个题有个坑，取值值是 0 <= ai < 2^30, 1 <= C < 2^30
 * 所以 A = B + C, int 存得下, 但是数组大小是 1 <= N < 2 * 10^5, 所以答案的范围应该是 0 ~ 4 * 10^5，这个int存不下
 */

#include <stdio.h>
#include <algorithm>

#define N 200005

typedef long long LL;
LL a[N];

int lower_bound(const LL arr[], int start, int end, LL query);
int upper_bound(const LL arr[], int start, int end, LL query);

int main()
{
    int n, c, lower_idx, upper_idx;
    scanf("%d %d", &n, &c);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }
    std::sort(a, a + n);
    LL ans = 0;
    for (unsigned i = 0; i < n; ++i) {
        lower_idx = lower_bound(a, i + 1, n, c + a[i]);
//        lower_idx = std::lower_bound(a + i + 1, a + n, a[i] + c) - a;
//        upper_idx = std::upper_bound(a + lower_idx, a + n, c + a[i]) - a;
//        ans += upper_idx - lower_idx;
        if (lower_idx >= 0) {
//            upper_idx = std::upper_bound(a + lower_idx, a + n, c + a[i]) - a;
            upper_idx = upper_bound(a, lower_idx, n, c + a[i]);
//            printf("B: %d, c: %d, lower_bound: %d, upper_bound: %d\n", a[i], c, lower_idx, upper_idx);
            ans += upper_idx - lower_idx;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

int lower_bound(const LL arr[], int start, int end, LL query) {
    int left = start, right = end, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (arr[mid] < query) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left < end && a[left] == query) {
        return left;
    } else {
        return -1;
    }
}

int upper_bound(const LL arr[], int start, int end, LL query) {
    int left = start, right = end, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (arr[mid] <= query) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}