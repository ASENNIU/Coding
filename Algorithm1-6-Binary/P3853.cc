//
// Created by 13345 on 2023/9/22.
//

#include <stdio.h>

#define N 10000000
int a[N];

bool judge(int n, int max_length, int k);

int main()
{
    int l, n, k;
    scanf("%d %d %d", &l, &n, &k);
    for (size_t i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int left = 1, right = l + 1, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        bool flag = judge(n, mid, k);
        if (flag) {
            right = mid;
        } else {
            left = mid + 1;
        }
//        printf("maxLength: %d, flag %d\n", mid, flag);
    }
    printf("%d\n", left);

    return 0;
}

bool judge(int n, int max_length, int k) {
    int cur_pos = 0, next_pos = 1, inserted = 0;
    while (next_pos < n ) {

        if (a[next_pos] - cur_pos > max_length) {
            ++inserted;
            if (inserted > k) {
                return false;
            }
            cur_pos = cur_pos + max_length;
        } else {
            cur_pos = a[next_pos];
            ++next_pos;
        }
    }

    return inserted <= k;
}