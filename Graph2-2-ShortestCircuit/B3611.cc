//
// Created by 13345 on 2023/12/1.
//

/***
 * Floyd求图的闭包加位运算压缩
 */
#include <bits/stdc++.h>
using namespace std;
int n, tmp;
bitset<110> a[110];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &tmp);
            a[i][j] = tmp;
        }
    }
    for (int j = 1; j <= n; j++)//注意j循环在i循环外
        for (int i = 1; i <= n; i++)
            if (a[i][j])
                a[i] |= a[j];//bitset也挺好写的
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            putchar(a[i][j] + '0'), putchar(' ');
        putchar('\n');
    }
    return 0;
}

