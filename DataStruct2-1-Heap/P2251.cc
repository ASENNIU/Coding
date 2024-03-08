//
// Created by 13345 on 2023/12/25.
//

#include <cstdio>
#include <queue>

#define MAX_N 1000007

int a[MAX_N];

int n, m;
std::deque<int> q;

int main()
{
    scanf("%d %d", &n, &m);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", a +i);
        while (q.size() && i - q.front() >= m) q.pop_front();
        while (q.size() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        if (i >= m) printf("%d\n", a[q.front()]);
    }

    return 0;
}