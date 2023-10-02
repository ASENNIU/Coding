//
// Created by 13345 on 2023/10/2.
//

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#define N 21

int is_link[N][N];
int is_used[N];
std::vector<std::string> words;
int n;
int ans;

int match(const std::string& str1, const std::string& str2);
void init();
void dfs(unsigned idx, int& cur_ans);

int main()
{

    std::string tmp;
    char c;
    scanf("%d", &n);
    for (unsigned i = 0; i < n; ++i) {
        std::cin >> tmp;
        words.push_back(tmp);
    }
    std::cin >> c;
    init();
//    std::cout << "is_link matrix" << '\n';
//    for (unsigned i = 0; i < n; ++i) {
//        for (unsigned j = 0; j < n; ++j) {
//            std::cout << is_link[i][j] << " ";
//        }
//        std::cout << '\n';
//    }

    for (unsigned i = 0; i < n; ++i) {
        if (words[i][0] == c) {
            int cur_ans = words[i].length();
            ++is_used[i];
            dfs(i, cur_ans);
            --is_used[i];
            ans = ans > cur_ans ?  ans : cur_ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}

int match(const std::string& str1, const std::string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    int match_length = 0x3f3f3f3f;
    for (unsigned i = 0; i < length1; ++i) {
        unsigned j = i, cur_match = 0;
        for (unsigned k = 0; j < length1 && k < length2; ++k, ++j) {
            if (str1[j] != str2[k]) {
                break;
            } else {
                ++cur_match;
            }
        }
        if (j == length1 && cur_match != 0 && cur_match != length1 && cur_match != length2) {
            match_length = match_length > cur_match ? cur_match : match_length;
        }
    }
    if (match_length != 0x3f3f3f3f) {
        return match_length;
    }
    else {
        return 0;
    }
}

void init() {
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            // 不排除某个单词可以接在自己的后面
//            if (i == j) {
//                continue;
//            }
            is_link[i][j] = match(words[i], words[j]);
        }
    }
}

void dfs(unsigned idx, int& cur_ans) {
    for (unsigned i = 0; i < n; ++i) {
        if (is_used[i] < 2 && is_link[idx][i]) {
            ++is_used[i];
            cur_ans += words[i].length() - is_link[idx][i];
            dfs(i, cur_ans);
            --is_used[i];
            cur_ans -= words[i].length() - is_link[idx][i];
        }
    }
    ans = ans > cur_ans ? ans : cur_ans;
}