//
// Created by 13345 on 2023/11/8.
//

#include <cstdio>

#define N 5005

int fa[N];

int find(int x) {
    while (fa[x] != x) {
        x = fa[x];
    }
    return x;
}

void combine(int a, int b) {
    fa[find(a)] = find(b);
}

int main()
{
    for (unsigned i = 0; i < N; ++i) {
        fa[i] = i;
    }
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    int a, b;
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        combine(a, b);
    }
    for (unsigned i = 0; i < p; ++i) {
        scanf("%d %d", &a, &b);
        if (find(a) == find(b)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}