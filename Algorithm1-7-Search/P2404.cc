//
// Created by 13345 on 2023/10/3.
//

/***
 * 搜索加剪枝，怎么定义剪枝和退出行为
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
int dfs(int n, int num, int cur_sum, vector<int>& cur, vector<vector<int>>& ans);

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(n, 1, 0, cur, ans);
    std::sort(ans.begin(), ans.end(),
              [](vector<int>& a, vector<int>& b) {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        int length = std::min(a.size(), b.size());
        for (unsigned i = 0; i <length; ++i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    });
    for (unsigned i = 0; i < ans.size(); ++i) {
        for(unsigned j = 0; j < ans[i].size() - 1; ++j) {
            printf("%d+", ans[i][j]);
        }
        printf("%d\n", ans[i].back());
    }

    return 0;
}

int dfs(int n, int num, int cur_sum, vector<int>& cur, vector<vector<int>>& ans) {
    if (cur_sum == n) {
        ans.push_back(cur);
        return 0;
    } else if (cur_sum > n) {
        return 1;
    }
    for (int i = num; i < n; ++i) {
        cur.push_back(i);
        int res = dfs(n, i, cur_sum + i, cur, ans);
//        if (res > 0) {
//            cur.pop_back();
//            return 0;
//        }
        cur.pop_back();
    }
}