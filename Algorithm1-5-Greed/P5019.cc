//
// Created by 13345 on 2023/9/6.
//

#include <cstdio>

int main()
{
    int n, pre = 0, cur, ans = 0;
    scanf("%d", &n);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", &cur);
        if (cur > pre) {
            ans += cur - pre;
        }
        pre = cur;
    }
    printf("%d", ans);
    return 0;
}