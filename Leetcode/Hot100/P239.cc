#include <bits/stdc++.h>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
  std::deque<int> q;
  int i = 0, j = 0;
  std::vector<int> ret;
  while (j < nums.size()) {
    while (!q.empty() && nums[j] > nums[q.back()]) {
      q.pop_back();
    }
    q.push_back(j);
    if (j - i + 1 >= k) {
      ret.push_back(nums[q.front()]);
      if (q.front() == i) {
        q.pop_front();
      }
      ++i;
    }
    ++j;
  }
  return ret;
}

int main()
{
  std::vector<int> nums{1,3,-1,-3,5,3,6,7};
  int k = 3;
  std::vector<int> ans = maxSlidingWindow(nums, k);
  for (int it : ans) {
    std::cout << it <<  " ";
  }
}
