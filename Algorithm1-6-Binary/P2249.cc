//
// Created by 13345 on 2023/9/15.
//

#include <stdio.h>

#define N 1000000 + 5
#define M 100000 + 5

int a[N];
int query[M];

int lower_bound(int a[], int n, int query);

int main()
{
    int n, m, idx;
    scanf("%d %d", &n, &m);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d", query + i);
    }

    for (unsigned i = 0; i < m; ++i) {
        idx = lower_bound(a, n, query[i]);
        if (idx < 0) {
            printf("%d ", idx);
        } else {
            printf("%d ", idx + 1);
        }
    }
    return 0;
}

int lower_bound(int a[], int n, int query) {
    int left = 0, right = n, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (a[mid] < query) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (a[left] == query) {
        return left;
    } else {
        return -1;
    }
}