//
// Created by 13345 on 2023/10/17.
//

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

int main()
{
    long long ans = 0;
    int n, tmp;
    std::set<int> value_set;
    value_set.insert(0x3f3f3f3f);
    value_set.insert(-0x3f3f3f3f);
    scanf("%d", &n);
    scanf("%d", &tmp);
    ans += tmp;
    value_set.insert(tmp);
    while (--n) {
        scanf("%d", &tmp);
        auto it = value_set.lower_bound(tmp);
        auto max_it = it--;
        ans += std::min(abs(tmp - *it), abs(tmp - *max_it));
        value_set.insert(tmp);

    }
    printf("%lld", ans);

    return 0;
}