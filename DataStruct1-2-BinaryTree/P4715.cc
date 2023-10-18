//
// Created by 13345 on 2023/10/18.
//

#include <vector>
#include <utility>
#include <cstdio>

using team = std::pair<int, int>;

int main()
{
    int n, tmp;
    scanf("%d", &n);
    std::vector<team> teams;
    int total = 1 << n;
    for (int i = 1; i <= total; ++i) {
        scanf("%d", &tmp);
        teams.emplace_back(i, tmp);
    }
    while (--n) {
        std::vector<team> next;
        for (int i = 0; i < teams.size(); i += 2) {
            team a = teams[i];
            team b = teams[i + 1];
            if (a.second > b.second) {
                next.push_back(a);
            } else {
                next.push_back(b);
            }
        }
        std::swap(teams, next);
    }
    int ans = teams[0].second > teams[1].second ? teams[1].first : teams[0].first;
    printf("%d\n", ans);

    return 0;
}