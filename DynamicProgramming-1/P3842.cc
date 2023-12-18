//
// Created by 13345 on 2023/12/18.
//

#include <cstdio>
#include <algorithm>

#define MAX_N 20005

int point[MAX_N][2], dp_l[MAX_N], dp_r[MAX_N];

int main()
{
    int n;
    scanf("%d", &n);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    point[0][0] = 1;
    point[0][1] = 1;
    point[n+1][0] = n;
    point[n+1][1] = n;
    for (unsigned i = 1; i <= n + 1; ++i) {
        dp_l[i] = std::min(
                std::abs(point[i][1] - point[i-1][0]) + point[i][1] - point[i][0] + dp_l[i-1],
                std::abs(point[i][1] - point[i-1][1]) + point[i][1] - point[i][0] + dp_r[i-1]
                );
        dp_r[i] = std::min(
                std::abs(point[i][0] - point[i-1][0]) + point[i][1] - point[i][0] + dp_l[i-1],
                std::abs(point[i][0] - point[i-1][1]) + point[i][1] - point[i][0] + dp_r[i-1]
        );
    }

    printf("%d\n", dp_l[n+1] + n - 1);
    return 0;
}