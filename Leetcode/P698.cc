//
// Created by 13345 on 2023/9/18.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> state;

bool dfs(vector<int>& nums, int idx, vector<int>& bucket, int per);
bool dfs(vector<int>& nums, int idx, vector<int>& bucket, int bucket_num, int per, int used);

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % k)
            return false;
        int per = sum / k;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > per)
            return false;
        vector<int> bucket(k + 1, 0);
        int used = 0;
        return dfs(nums, 0, bucket, k, per, used);
//        return dfs(nums, 0, bucket, per);
    }
};

bool dfs(vector<int>& nums, int idx, vector<int>& bucket, int per) {
    if (idx == nums.size())
        return true;

    for (unsigned i = 1; i < bucket.size(); ++i) {
        if (i > 1 && bucket[i] == bucket[i - 1])
            continue;
        if (bucket[i] + nums[idx] > per)
            continue;
        bucket[i] += nums[idx];
        if (dfs(nums, idx + 1, bucket, per))
            return true;
        bucket[i] -= nums[idx];
    }

    return false;
}

bool dfs(vector<int>& nums, int idx, vector<int>& bucket, int bucket_num, int per, int used) {
//    printf("bucket num: %d\n", bucket_num);
    if (bucket_num == 0)
        return true;
    if (bucket[bucket_num] == per) {
//        printf("bucket %d success\n", bucket_num);
        bool res =  dfs(nums, 0, bucket, bucket_num - 1, per, used);
//        state[used] = res;
        return res;
    }

    for (unsigned i = idx; i < nums.size(); ++i) {
        int flag = 1 << i ;
        if (used & flag)
            continue;
        if (bucket[bucket_num] + nums[i] > per)
            continue;
        bucket[bucket_num] += nums[i];
        used |= flag;
//        printf("bucket %d: %d, used: %d, cur_index: %d\n", bucket_num, bucket[bucket_num], used, i);
        if (dfs(nums, i + 1, bucket, bucket_num, per, used))
            return true;
        bucket[bucket_num] -= nums[i];
        used ^= flag;
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
    }

    return false;
}


int main()
{
    vector<int> nums{1, 1};
    int k = 2;
    Solution s;
    cout << s.canPartitionKSubsets(nums, k) << endl;

    return 0;
}