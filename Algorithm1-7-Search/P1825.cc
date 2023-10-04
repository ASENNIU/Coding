//
// Created by 13345 on 2023/10/4.
//

#include <iostream>
//#include <utility>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

#define N 305

struct point {
    int x, y,step;
    point(int x, int y, int  t) : x(x), y(y), step(t) {}
    bool operator==(const point& other) const {
        return other.x == x && other.y == y;
    }
    point() {
        x = -1;
        y = -1;
        step = 0;
    }
};

int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};

bool vis[N][N];
std::unordered_map<char, std::vector<point>> gateway;
std::vector<std::string> map;
int n, m;

int main()
{
    std::cin >> n >> m;
    std::string tmp;
    for (unsigned i = 0; i < n; ++i) {
        std::cin >> tmp;
        map.push_back(tmp);
    }
    point start, end;
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {
            if (map[i][j] == '@') {
                start.x = i;
                start.y = j;
                start.step = 0;
            } else if (map[i][j] == '=') {
                end.x = i;
                end.y = j;
                end.step = -1;
            } else if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
                gateway[map[i][j]].emplace_back(i, j, -1);
            }
        }
    }

    std::queue<point> q;
    q.push(start);
    vis[start.x][start.y] = true;
    while(!q.empty()) {
        point p = q.front();
        q.pop();
        for (unsigned i = 0; i < 4; ++i) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if (x >= 0 && x <= n && y >= 0 && y <= m && !vis[x][y] && map[x][y] != '#') {
                if (map[x][y] == '.') {
                    q.emplace(x, y, p.step + 1);
                    vis[x][y] = true;
                } else if (map[x][y] >= 'A' && map[x][y] <= 'Z') {
//                    vis[x][y] = true;
//                    q.emplace(x, y, p.step + 1);
                    for (unsigned  j = 0; j < gateway[map[x][y]].size(); ++j) {
                        if (!(gateway[map[x][y]][j].x == x && gateway[map[x][y]][j].y == y)) {
                            q.emplace(gateway[map[x][y]][j].x, gateway[map[x][y]][j].y, p.step + 1);

//                            vis[gateway[map[x][y]][j].x][gateway[map[x][y]][j].y] = true;
                        }
                    }
                } else if (map[x][y] == '=') {
                    std::cout << p.step + 1 << std::endl;
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}