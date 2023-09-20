//
// Created by 13345 on 2023/9/20.
//

#include <stdio.h>
#include <algorithm>

#define N 100005

int school[N];
int score[N];

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d", school + i);
    }
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", score + i);
    }
    std::sort(school, school + m);

    long long ans = 0;
    for (unsigned i = 0; i < n; ++i) {
        auto idx = std::upper_bound(school, school + m, score[i]) - school;
        if (idx == 0) {
            ans += school[idx] - score[i];
        } else if (idx == m) {
            ans += score[i] - school[m - 1];
        } else {
            ans += std::min(school[idx] - score[i] , score[i] - school[idx - 1]);
        }
//        printf("idx: %d, score: %d\n", idx, score[i]);
    }
    printf("%lld\n", ans);

    return 0;
}