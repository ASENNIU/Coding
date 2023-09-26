//
// Created by 13345 on 2023/9/26.
//

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define N 405

struct point {
    int x, y;
    point(int x, int y) : x(x), y(y) {}
};

int map[N][N];
bool used[N][N];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {2,1,-1,-2,2,1,-1,-2};

void bfs(int n, int m, std::queue<point>& waiting);

int main()
{
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    memset(map, -1, N * N);
    std::queue<point> waiting;
    waiting.emplace(x, y);
    used[x][y] = true;
    map[x][y] = 0;
    bfs(n, m, waiting);
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j <= m; ++j) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void bfs(int n, int m, std::queue<point>& waiting){

    while (!waiting.empty()) {
        point p = waiting.front();
        waiting.pop();
        for (int i = 0; i < 8; ++i) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if (x < 1 || y < 1 || x > n || y > m || used[x][y]) {
                continue;
            }
            map[x][y] = map[p.x][p.y] + 1;

            used[x][y] = true;
            waiting.emplace(x, y);

        }
    }

}