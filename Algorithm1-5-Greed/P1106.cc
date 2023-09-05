//
// Created by 13345 on 2023/9/5.
//


#include <cstdio>
#include <cstring>
#include <list>

char value[255];


int main()
{
    int k;
    scanf("%s\n", value);
    scanf("%d", &k);
    unsigned value_length = strlen(value);
    if (k >= value_length) {
        printf("0\n");
        return 0;
    }
    std::list<int> value_list;
    for (unsigned i = 0; i < value_length; ++i)
    {
        value_list.emplace_back(value[i] - '0');
    }
    int rm = 0;
    while (rm < k) {
        auto p = value_list.begin();
        auto cur = p++;
        while (p != value_list.end() && *cur <= *p)
        {
            cur = p++;
        }
        if (p == value_list.end())
            break;
        else {
            value_list.erase(cur);
            ++rm;
        }
    }
//    for (auto & p : value_list)
//        printf("%d ", p);
//    printf("\n");

    long long ans = 0;
    auto p = value_list.begin();
    for (unsigned i = 0; i < value_length - k; ++i)
    {
        ans = ans * 10 + *p;
        ++p;
    }
    printf("%lld\n", ans);
    return 0;
}