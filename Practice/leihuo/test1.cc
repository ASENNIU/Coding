#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1005;
int n;

int main() {
  std::cin >> n;
  std::vector<int> votes(10, 0);
  for (int i = 0; i < n; ++i) {
    std::vector<int> play(10, 0);
    for (int j = 0; j < 10; ++j) {
      std::cin >> play[j];
    }

    int exp_count = 0;
    int vote_count = 0;

    for (int c : play) {
      if (c == 1 || c == 2) {
        ++exp_count;
      }
      if (c == 2) {
        ++vote_count;
      }
    }
    int max_v = std::min(exp_count - 2, 5);

    if (exp_count < 3 || vote_count > max_v) {
      continue;
    } else {
      for (int j = 0; j < 10; ++j) {
        if (play[j] == 2) {
          ++votes[j];
        }
      }
    }
  }

  std::vector<int> ans;
  int val = *std::max_element(votes.begin(), votes.end());
  for (int j = 0; j < 10; ++j) {
    if (votes[j] == val) {
      ans.push_back(j + 1);
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    std::cout << ans[i] << " ";
  }

  return 0;
}
// 64 位输出请用 printf("%lld")