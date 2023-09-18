//
// Created by 13345 on 2023/9/16.
//


#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> getLuckyNum(vector<vector<int>>& nums) {
        vector<pair<int, int>> num2count(34);
        for (int i = 1; i <= 33; ++i) {
            num2count[i] = make_pair(i, 0);
        }
        for (unsigned i = 0; i < nums.size(); ++i) {
            for (unsigned j = 0; j < nums[i].size(); ++j) {
                ++num2count[nums[i][j]].second;
            }
        }

        sort(num2count.begin() + 1, num2count.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
           if (a.second < b.second) {
               return true;
           }
           else if (a.second == b.second)
                return a.first < b.first;
           else {
               return false;
           }
        });
        vector<int> ans;
        for (int i = 1; i <= 7; ++i) {
            ans.push_back(num2count[i].first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<vector<int>> input{
        {1,2,3,4,5,6,7},
        {8,9,10,11,12,13,14},
        {15,16,17,18,19,20,21},
        {22,23,24,25,26,27,28}};
    Solution s;
    vector<int> ans = s.getLuckyNum(input);

    for (int i = 0; i < ans.size(); ++i)
        std::cout << ans[i] << " ";

    return 0;
}