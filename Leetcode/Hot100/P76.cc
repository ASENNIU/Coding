// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 注意：
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。

#include <bits/stdc++.h>

std::string s, t;
int target[128];
int window[128];
int valid = 0, required = 0;

std::string solve() {
  for (char c : t) {
    target[c]++;
    ++required;
  }
  int l = 0,  r = 0, ans = -1, len = 1e9;
  while (r < s.size()) {
    if (target[s[r]] != 0) {
      if (++window[s[r]] <= target[s[r]]) {
        ++valid;
      }
    }
    while (valid == required) {
      if (r - l + 1 < len) {
        len = r - l + 1;
        ans = l;
      }
      if (target[s[l]] != 0) {
        if (--window[s[l]] < target[s[l]]) {
          --valid;
        }
      }
      ++l;
    }
    ++r;
  }
  return ans == -1 ? "" : s.substr(ans, len);
}
int main()
{
  std::cin >> s >> t;
  std::string ret = solve();

  std::cout << ret << std::endl;
  return 0;
}