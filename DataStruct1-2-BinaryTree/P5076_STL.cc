//
// Created by 13345 on 2023/11/7.
//

#include <cstdio>
#include <set>

const int INF = 0x7fffffff;
std::multiset<int> tree;

int main()
{
    tree.insert(INF);
    tree.insert(-INF);
    int n, opt, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &opt, &x);
        switch (opt) {
            case 1:
            {
                auto it = tree.lower_bound(x);
//                int order = 0;
//                for (auto i = tree.begin(); i != it; ++i) {
//                    ++order;
//                }
                int order = std::distance(tree.begin(), it);
                printf("%d\n", order);
                break;
            }
            case 2:
            {
                int order = -1;
                for (int i : tree) {
                    if (++order == x) {
                        printf("%d\n", i);
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                auto it = tree.lower_bound(x);
                printf("%d\n", *(--it));
                break;
            }
            case 4:
            {
                auto it = tree.upper_bound(x);
                printf("%d\n", *it);
                break;
            }
            case 5:
            {
                tree.insert(x);
            }
        }
    }

    return 0;
}