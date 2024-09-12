#include <bits/stdc++.h>

#define MAXN 5000

std::string s;
bool isPalindrome[MAXN][MAXN] = {0};
int dp[MAXN] = {0};
int n;

int solve() {
  for (int i = 0; i < n; ++i) {
    isPalindrome[i][i] = true;
  }

  for (int length = 2; length <= n; ++length) {
    for (int i = 0; i <= n - length; ++i) {
      int j = i + length - 1;
      if (s[i] == s[j]) {
        if (length == 2) {
          isPalindrome[i][j] = true;
        } else {
          isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
        }
      }
    }
  }

  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (!isPalindrome[0][i]) {
      dp[i] = 1e9;
      for (int j = 0; j < i; ++j) {
        if (isPalindrome[j + 1][i]) {
          dp[i] = std::min(dp[i], dp[j] + 1);
        }
      }
    }
  }

  return dp[n - 1];
}

int main() {
  std::cin >> s;
  n = s.length();
  int ans = solve();
  std::cout << ans << std::endl;

  return 0;
}