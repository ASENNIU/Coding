//
// Created by 13345 on 2023/9/25.
//


/***
 * 这个题可以的，贪心和二分都需要用到
 * 求最值的方法，二分搜答案。这个思路很不错。理解题意，弄明白分界点的物理含义
 * 另外，二分的边界值应该是从测试点的反馈得到的
 */

#include <stdio.h>

#define N 100005
#define MIN 1e-6

int a[N];
int b[N];

bool judge(double max_time, int n, int p);

int main()
{
    int n, p;
    double sum_a = 0;
    scanf("%d %d", &n, &p);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d %d", a + i, b + i);
        sum_a += a[i];
    }
    if (sum_a <= p) {
        printf("-1\n");
        return 0;
    }

    double left = 0, right = 1e10, mid;
    while (right - left > MIN) {
        mid = (left + right) / 2;
        bool flag = judge(mid, n, p);
        if (flag) {
            left = mid;
        } else {
            right = mid;
        }
//        printf("time %.6f, flag %d\n", mid, flag);
    }

    printf("%.10f\n", left);
    return 0;
}

bool judge(double max_time, int n, int p) {
    double total_sum = 0;
    for (unsigned i = 0; i < n; ++i) {
        double cur = a[i] * max_time - b[i];
        if (cur > 0) {
          total_sum += cur;
        }
    }

    return max_time * p >= total_sum;
}
