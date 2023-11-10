//
// Created by 13345 on 2023/11/10.
//

#include <set>
#include <cstdio>

int main()
{
    int n, opt, x;
    std::set<int> repo;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &opt, &x);
        if (opt == 1) {
            if (repo.find(x) != repo.end()) {
                printf("Already Exist\n");
            } else {
                repo.insert(x);
            }
        } else {
            if (repo.empty()) {
                printf("Empty\n");
                continue;
            }
            auto it = repo.lower_bound(x);
            if (*it == x) {
                printf("%d\n", *it);
                repo.erase(it);
            } else {
                if (it == repo.begin()) {
                    printf("%d\n", *it);
                    repo.erase(it);
                } else if (it == repo.end()) {
                    printf("%d\n", *(--it));
                    repo.erase(it);
                } else {
                    auto upper = it--;
                    it = (*upper - x) >= (x - *it) ? it : upper;
                    printf("%d\n", *it);
                    repo.erase(it);
                }
            }
        }
    }

    return 0;
}

