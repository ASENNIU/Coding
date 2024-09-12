// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词
// 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 异位词
// 指由相同字母重排列形成的字符串（包括相同的字符串）。

#include <bits/stdc++.h>

std::string s, p;

// 维护 p.length()大小的窗口内字符的有效个数，当有效个数等于
// p.length()时即异位词
std::vector<int> solve1() {
  int hash[26] = {0};
  int target[26] = {0};
  int valid = 0;

  for (char c : p) {
    target[c - 'a']++;
  }
  std::vector<int> ans;
  for (int i = 0, j = 0; j < s.size(); ++j) {
    int inCode = s[j] - 'a';
    // 入窗判断
    if (++hash[inCode] == target[inCode]) {
      valid++;
    }

    // 出窗判断
    if (j - i + 1 > p.size()) {
      int outCode = s[i] - 'a';
      if (hash[outCode] == target[outCode]) {
        --valid;
      }
      --hash[outCode];
      ++i;
    }
    if (valid == p.size()) {
      ans.push_back(i);
    }
  }

  return ans;
}

int main() {
  std::cin >> s >> p;
  std::vector<int> ans = solve1();
  for (int idx : ans) {
    std::cout << idx << " ";
  }
  return 0;
}