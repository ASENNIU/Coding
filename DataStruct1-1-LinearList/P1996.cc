//
// Created by 13345 on 2023/10/16.
//

#include <queue>
#include <cstdio>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while (!q.empty()) {
        for (int i = 1; i <m; ++i) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int tmp = q.front();
        q.pop();
        printf("%d ", tmp);
    }
    return 0;
}