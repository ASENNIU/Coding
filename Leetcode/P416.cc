//
// Created by 13345 on 2023/9/18.
//

#include <vector>
#include <iostream>

using namespace std;

//bool dp(vector<int>& nums, int target);
bool dp_osp(vector<int>& nums, int target);

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        int target = 0;
        for (unsigned i = 0; i < nums.size(); ++i) {
            target += nums[i];
        }
        if (target & 1 )
            return false;
        target = target >> 1;
        return dp_osp(nums, target);
    }
};

int main()
{
    vector<int> nums{1,2, 10};
    Solution s;
    bool ans = s.canPartition(nums);
    cout << ans << endl;

    return ans;
}

bool dp_osp(vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (unsigned j = target; j >= num; --j) {
            dp[j] = dp[j] | dp[j - num];
        }
    }

    return dp[target];
}