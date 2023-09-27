//
// Created by 13345 on 2023/9/27.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define N 17

double x[N], y[N], dp[N][1 << N], dist[N][N];
int n;

double distance(double x1, double y1, double x2, double y2);
void init();

int main()
{
    scanf("%d", &n);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%lf %lf", x + i, y + i);
//        printf("%d: %f %f\n", i, x[i], y[i]);
    }

    x[0] = 0;
    y[0] = 0;
    init();
    for (unsigned i = 1; i <= n; ++i) {
        dp[i][1 << (i - 1)] = dist[0][i];
    }
    for (int k = 1; k < (1 << n); ++k) {
        for (int i = 1; i <= n; ++i) {
            if ((k & (1 << (i - 1))) == 0) {
                continue;
            }
            for (unsigned j = 1; j <= n; ++j) {
                if (i == j || (k & (1 << (j - 1))) == 0) {
                    continue;
                }
              
                dp[i][k] = std::min(dp[i][k], dp[j][k ^ (1 << (i - 1))] + dist[i][j]);
            }
        }
    }
    double ans = dp[0][0];
    int k = (1 << n) - 1;
    for (int i = 1; i <= n; ++i) {
        ans = std::min(ans, dp[i][k]);
    }
    printf("%.2f\n", ans);

    return 0;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void init() {
    for (unsigned i = 0; i <= n; ++i) {
        for (unsigned j = i + 1; j <= n; ++j) {
            dist[i][j] = distance(x[i], y[i], x[j], y[j]);
            dist[j][i] = dist[i][j];
        }
    }
    memset(dp, 127, sizeof(dp));
}
