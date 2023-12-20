//
// Created by 13345 on 2023/12/20.
//

#include <cstdio>
#include <queue>

#define N 100005

std::priority_queue<int> q_max;
std::priority_queue<int, std::vector<int>, std::greater<int>> q_min;
int a[N];

int main()
{
    int n, mid;
    scanf("%d", &n);
    scanf("%d", a + 1);
    mid = a[1];
    printf("%d\n", mid);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", a + i);
        if (a[i] > mid) {
            q_min.push(a[i]);
        } else {
            q_max.push(a[i]);
        }
        if (i & 1) {
            while (q_max.size() != q_min.size()) {
                if (q_max.size() > q_min.size()) {
                    q_min.push(mid);
                    mid = q_max.top();
                    q_max.pop();
                } else {
                    q_max.push(mid);
                    mid = q_min.top();
                    q_min.pop();
                }
            }
            printf("%d\n", mid);
        }

    }

    return 0;
}
