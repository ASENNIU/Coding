//
// Created by 13345 on 2023/9/8.
//

#include <map>
#include <stdio.h>
#include <algorithm>

void print(std::map<int, int> map);

int main()
{
    int n, tmp, cur_length, ans = 0x3f3f3f3f;
    std::map<int, int> val2count;
    typedef std::map<int, int>::iterator it;
    scanf("%d", &n);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        ++val2count[tmp];
    }
    while (!val2count.empty()) {
        it cursor = val2count.begin();
        it begin = val2count.begin();
        cur_length = 1;
        while (true) {
            it pre = cursor++;
            if (cursor == val2count.end()) {
                ans = std::min(ans, cur_length);
                break;
            }
            else if (cursor->first != pre->first + 1) {
                ans = std::min(ans, cur_length);
                break;
            }
            else if (pre->second <= cursor->second) {
                ++cur_length;
            }
            else {
                ans = std::min(ans, cur_length);
                break;
            }
        }
        for (;begin != cursor; ) {
            it tmp = begin++;
            if (--tmp->second == 0) {
                val2count.erase(tmp);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

void print(std::map<int, int> map) {
    for (auto& it : map) {
        printf("(%d, %d) ", it.first, it.second);
    }
    printf("\n");
}