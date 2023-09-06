//
// Created by 13345 on 2023/9/6.
//

#include <cstdio>
#include <map>

int main()
{
    int n, m, price, produce;
    scanf("%d %d", &n, &m);
    std::multimap<int, int> produces;
    for (unsigned i = 0; i < m; ++i) {
        scanf("%d %d", &price, &produce);
        produces.emplace(price, produce);
    }
    long long ans = 0;
    for (auto& item : produces) {
//        printf("%d ", item.first);
        if (n >= item.second) {
            n -= item.second;
            ans += item.first * item.second;
        } else {
            ans += n * item.first;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}