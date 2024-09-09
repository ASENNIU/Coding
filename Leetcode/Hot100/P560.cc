#include <bits/stdc++.h>

int solve(const std::vector<int>& nums, int k) {
  int prefixSum = 0;
  std::unordered_map<int, int> prefixSumCount;
  prefixSumCount[0] = 1;
  int ret = 0;
  for (int num : nums) {
    prefixSum += num;
    if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
      ret += prefixSumCount[prefixSum - k];
    }

    prefixSumCount[prefixSum]++;
  }
  return ret;
}

int main() {
  std::vector<int> arr{1, 2, 3};
  int k = 3;
  int ans = solve(arr, k);

  std::cout << ans << std::endl;

  return 0;
}