//
// Created by 13345 on 2023/12/19.
//

// 用一个大根堆一个小根堆维护第K小元素
// 维护大根堆中始终有K个元素，而小根堆中的元素大于大根堆中的元素

#include <cstdio>
#include <queue>

#define N 200005

int a[N], u[N], m, n, i;
std::priority_queue<int, std::vector<int>, std::greater<int>> q_min;
std::priority_queue<int, std::vector<int>, std::less<int>> q_max;

int main()
{
    scanf("%d %d", &m, &n);
    for (unsigned j = 1; j <= m; ++j) {
        scanf("%d", a + j);
    }
    for (unsigned j = 1; j <= n; ++j) {
        scanf("%d", u + j);
    }

    for (unsigned j = 1; j <= n; ++j) {
        while (i < u[j]) {
            ++i;
            q_max.push(a[i]);
            q_min.push(q_max.top());
            q_max.pop();
        }
        printf("%d\n", q_min.top());
        q_max.push(q_min.top());
        q_min.pop();
    }
    return 0;
}