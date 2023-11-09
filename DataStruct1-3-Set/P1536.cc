//
// Created by 13345 on 2023/11/8.
//

#include <cstdio>

#define N 1005
int fa[N];

void init(int n) {
    for (unsigned i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int find(int x) {
    int t1 = x, t2;
    while (fa[x] != x) {
        x = fa[x];
    }

    // 路径压缩
    while (fa[t1] != t1) {
        t2 = fa[t1];
        fa[t1] = x;
        t1 = t2;
    }
    return x;
}

void combine(int a, int b) {
    fa[find(a)] = find(b);
}

int main()
{
    int n, m;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        scanf("%d", &m);
        init(n);
        int a, b, ans = 0;
        for (unsigned i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            combine(a, b);
        }
        for (unsigned i = 1; i <= n; ++i) {
            if (find(i) == i) {
                ++ans;
            }
        }
        printf("%d\n", ans - 1);
    }

    return 0;
}