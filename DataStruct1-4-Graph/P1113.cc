////
//// Created by 13345 on 2023/11/21.
////
//
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXN 10005
std::vector<int> edges[MAXN];

int total_time, ind[MAXN], cur_task[MAXN], fa[MAXN];

int main()
{
    int n, task, t_time, pre_num;
    std::queue<int> q;
    scanf("%d", &n);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d %d", &task, &t_time);
        while (scanf("%d", &pre_num) && pre_num) {
            ind[task]++;
            edges[pre_num].push_back(task);
        }
        cur_task[task] = t_time;
    }

    for (unsigned i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
            fa[i] = cur_task[i];
        }
    }

    while (!q.empty()) {
        int rhs = q.front();
        q.pop();
        for (unsigned i = 0; i < edges[rhs].size(); ++i) {
            int u = edges[rhs][i];
            --ind[u];
            if (ind[u] == 0) {
                q.push(u);
            }
            fa[u] = std::max(fa[rhs] + cur_task[u], fa[u]);
        }

    }
    for (unsigned i = 1; i <= n; ++i) {
        total_time = std::max(total_time, fa[i]);
    }
    printf("%d\n", total_time);
    return 0;
}

