//
// Created by 13345 on 2023/9/6.
//

#include <cstdio>
#include <algorithm>
#define N 30005

int a[N];

int main()
{
    int w, n;
    scanf("%d %d", &w, &n);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    int left = 0, right = n -1;
    int ans = 0;
    while(left <= right) {
        if (left == right) {
            ++ans;
            break;
        }
        else if (a[left] + a[right] <= w) {
            ++left;
            --right;
            ++ans;
        } else {
            --right;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}