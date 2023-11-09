//
// Created by 13345 on 2023/11/8.
//

#include <cstring>
#include <unordered_set>
#include <cstdio>
#include <cmath>

#define MAXN 1505

char str[MAXN];
const long long base = 256;

int main()
{
    int n;
    long long hash_key;
    scanf("%d", &n);
    std::unordered_set<long long > hash_map;
    for (unsigned i = 0; i < n; ++i) {
        scanf("%s", str);
        hash_key = 0;
        for (unsigned j = 0; j < strlen(str); ++j) {
            hash_key = hash_key * base + str[j];
        }
        memset(str, 0, strlen(str));
        hash_map.insert(hash_key);
    }
    int ans = hash_map.size();
    printf("%d\n", ans);

    return 0;
}