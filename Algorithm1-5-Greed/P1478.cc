//
// Created by 13345 on 2023/9/6.
//

#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
    int n, s, a, b, x, y;
    scanf("%d %d", &n, &s);
    scanf("%d %d", &a, &b);
    std::vector<int> consume;
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if (x <= (a + b)) {
            consume.push_back(y);
        }
    }
    sort(consume.begin(), consume.end());
    int ans = 0, idx = 0;
    while (idx < consume.size()) {
        if (s >= consume[idx]) {
            ++ans;
            s -=consume[idx];
            ++idx;
        } else {
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}