//
// Created by 13345 on 2023/10/4.
//

/***
 * std::basic_string<CharT,Traits,Allocator>::find_first_of
 * 查找第一个字符等于给定字符序列中的一个字符。搜索只考虑 [pos, size()) 范围。如果范围内没有给定字符序列中的任何字符，将返回 npos。
 * 即匹配的是字符，源字符串和目标字符串中第一个匹配的字符
 *
 * std::basic_string<CharT,Traits,Allocator>::find
 * 查找与给定字符序列相同的第一个子串。搜索从 pos 开始，即找到的子串不得从 pos 之前的位置开始。
 *
 * std::basic_string<CharT,Traits,Allocator>::replace
 * 用给定的字符替换 [begin() + pos, begin() + std::min(pos + count, size())] 或 [first, last] 范围内的字符。
 * 替换是inplace的
 */

#include <string>
#include <unordered_map>
#include <iostream>
#include <queue>

#define MAX_STEP 10
#define MAPPING_NUM 7


struct state {
    std::string str;
    int step;
    state(std::string& str, int step) : str(str), step(step) {}
};

std::string s_str[MAPPING_NUM], d_str[MAPPING_NUM];

int main()
{
    std::string src, dst, str1, str2;
    std::cin >> src >> dst;
//    std::unordered_map<std::string, std::string> mapping;
    std::unordered_map<std::string, int> vis;
    int n = 0;
    while (std::cin >> s_str[n] >> d_str[n]) {
        ++n;
//        std::cout << "mapping: " << str1 << " -> " << str2 << std::endl;
    }
    std::queue<state> q;
    q.emplace(src, 0);
    int ans = 0;
    while (!q.empty()) {
        state s = q.front();
        q.pop();
//        std::cout << "handle str: " << s.str << " step: " << s.step << std::endl;
        if (s.str == dst) {
            ans = s.step;
            break;
        }
        if (s.step > MAX_STEP) {
            ans = s.step;
            break;
        }
        if (vis.find(s.str) != vis.end()) {
            continue;
        } else {
            vis[s.str] = s.step;
        }


        for (unsigned i = 0; i < n; ++i) {
            auto pos = s.str.find(s_str[i], 0);
            while (pos != std::string::npos) {
                std::string new_str(s.str);
                new_str.replace(pos, s_str[i].length(), d_str[i]);
                q.emplace(new_str, s.step + 1);
                pos = s.str.find(s_str[i], pos + 1);
            }

        }


    }

    if (ans != 0 && ans <= MAX_STEP) {
        std::cout << ans << std::endl;
    } else {
        std::cout << "NO ANSWER!" << std::endl;
    }

    return 0;
}