//
// Created by 13345 on 2023/12/2.
//

#include<iostream>
#include<cstdio>
using namespace std;
int a,b,n,m,f[101][101],ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        f[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = f[i][j] | f[i][k] & f[k][j];
    for (int i = 1; i <= n; i++) {
        int gg = 1;
        for (int j = 1; j <= n; j++)
            if (i == j)continue;
            else
                gg = gg & (f[i][j] | f[j][i]);
        ans += gg;
    }
    printf("%d\n", ans);
}