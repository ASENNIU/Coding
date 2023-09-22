//
// Created by 13345 on 2023/9/22.
//

#include <stdio.h>
#include <algorithm>

#define N 100005
int a[N];

bool judge(int n, int cur_max, int m);

int main()
{
    int n, m, mid, left = 0, right = 1e9 + 1;
    scanf("%d %d", &n, &m);
    for (size_t i = 0; i < n; ++i) {
        scanf("%d", a + i);
        left = std::max(left, a[i]);
    }
    while (left < right) {
        mid = (left + right) >> 1;
        bool flag = judge(n, mid, m);
        if (flag) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%d\n", left);

    return 0;
}

bool judge(int n, int cur_max, int m) {
    int cur_sum = 0, k = 1;
    for (size_t i = 0; i < n; ++i) {
        if (cur_sum + a[i] <= cur_max) {
            cur_sum += a[i];
        } else {
            cur_sum = a[i];
            ++k;
            if (k > m) {
                return false;
            }
        }
    }

    return true;
}