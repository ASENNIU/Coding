//
// Created by 13345 on 2023/9/27.
//

/***
 * void* memset( void* dest, int ch, std::size_t count );
 * 将 static_cast<unsigned char>(ch) 的值复制到 dest 指向的对象的每个前计数字符中
 * 1. 字符
 *   如果文本使用字符类型，请使用未限定的 char：
 *   它是字符字面类型，如 "a "或"0"（仅在 C++ 中，在 C 语言中它们的类型是 int）
 *   它是组成 C 字符串（如 "abcde"）的类型
 *   它也可以作为数字值使用，但未说明该值被视为有符号还是无符号。通过不等式进行字符比较时要小心--不过，如果你将自己限制在 ASCII（0-127）范围内，那就差不多安全了。
 * 2. 有符号字符/ 3. 无符号字符
 *   如果将字符类型用作数字，请使用
 *   signed char，它至少提供 -127 至 127 的范围。(通常为 -128 至 127）
 *   无符号 char，至少提供 0 至 255 的范围。这对于显示八进制值（如十六进制值）可能很有用。
 *   "sizeof（char）必须是 1（即一个字节），但一个字节理论上可以是 32 位，例如，sizeof 仍会将其大小报告为 1，这意味着可以使用 sizeof（char）== sizeof（long）== 1。
 */

#include <cstdio>
#include <queue>
#include <cstring>
#define N 305

int dx[5]{0, -1, 0, 1, 0};
int dy[5]{0, 0, 1, 0, -1};

int map[N][N];
bool vis[N][N];

struct action {
    int x, y, t;
    action(int x, int y, int t) : x(x), y(y), t(t) {}
};

int main()
{
    int m, t, x, y;
    // 这种方式也能过，但是是巧合，对于整数的填充还是循环遍历更好，memset按字节填充容易出错
    // -1的补码为 111....111，所有位都为1，所以可以memset做
    memset(map, -1, sizeof(int) * N * N);
//    for (int i=0;i<305;i++){
//        for (int j=0;j<305;j++){
//            map[i][j]=-1;
//        }
//    }//陨石初始化为-1
    scanf("%d", &m);
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &t);
        for (unsigned j = 0; j < 5; ++j) {
            int u = x + dx[j];
            int v = y + dy[j];
            if (u >= 0 && v >= 0) {
                if (map[u][v] == -1) {
                    map[u][v] = t;
                } else {
                    map[u][v] = std::min(map[u][v], t);
                }
            }
        }
    }

    std::queue<action> q;
    q.emplace(0, 0, 0);
    vis[0][0] = true;
    while (!q.empty()) {
        action cur = q.front();
        q.pop();
        for (int i = 1; i < 5; ++i) {
            int u = cur.x + dx[i];
            int v = cur.y + dy[i];
            if (u >= 0 && v >= 0 && !vis[u][v]) {
                vis[u][v] = true;
                if (map[u][v] == -1) {
                    printf("%d\n", cur.t + 1);
                    return 0;
                } else {
                    if (cur.t + 1 < map[u][v]) {
                        q.emplace(u, v, cur.t + 1);
                    }
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}

