//
// Created by 13345 on 2023/9/26.
//

#include <cstdio>
#include <algorithm>

#include <queue>
#define N 205

int arr[N];
bool vis[N];

struct action {
    int layer, step;
    action(int layer, int step) : layer(layer), step(step) {}
};

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
    }
    std::queue<action> q;
    q.emplace(a, 0);
    vis[a] = true;
    while (!q.empty()) {
        action  cur = q.front();
        q.pop();
        if (cur.layer == b) {
            printf("%d\n", cur.step);
            return 0;
        }
        if (cur.layer - arr[cur.layer] > 0 && !vis[cur.layer - arr[cur.layer]]) {
            q.emplace(cur.layer - arr[cur.layer], cur.step + 1);
            vis[cur.layer - arr[cur.layer]] = true;
        }
        if (cur.layer + arr[cur.layer] <= n && !vis[cur.layer + arr[cur.layer]]) {
            q.emplace(cur.layer + arr[cur.layer], cur.step + 1);
            vis[cur.layer + arr[cur.layer]] = true;
        }

    }
    printf("-1\n");
    return 0;
}