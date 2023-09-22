//
// Created by 13345 on 2023/9/21.
//

#include <stdio.h>

#define N 50005
int a[N];

bool judge(int n, int m, int min_length);

int main()
{
    int l, n, m;
    scanf("%d %d %d", &l, &n, &m);
    for (size_t i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    a[n+1]=l;
    int left = 1, right = l + 1, mid;
    while (left + 1 < right) {
        mid = (left + right) >> 1;
        bool flag = judge(n, m, mid);
        if (flag) {
            left = mid;
        } else {
            right = mid;
        }
        // printf("left %d, right %d, mid %d, flag %d\n", left, right, mid, flag);
    }
    printf("%d\n", left);
    return 0;
}


bool judge(int n, int m, int min_length) {
    int cur_pos = 0, moved = 0, next_pos = 0;
    while (next_pos < n + 1) {
        ++next_pos;
        if (a[next_pos] - a[cur_pos] < min_length) {
            ++moved;
        } else {
            cur_pos = next_pos;
        }
    }

    return moved <= m;
}