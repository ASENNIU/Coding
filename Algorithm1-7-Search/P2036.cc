//
// Created by 13345 on 2023/9/27.
//

/***
 * dfs中要注意到达边退出和check的顺序
 */

#include <cstdio>
#include <cmath>
#include <algorithm>

#define N  11
struct food{
    int s, b;
};

food foods[N];
int n;

void dfs(int idx, int cur_s, int cur_b, int& ans, bool use_flag);

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &foods[i].s, &foods[i].b);
    }
    int ans = 0x3f3f3f3f;
    dfs(0, 1, 0, ans, false);
    printf("%d\n", ans);

    return 0;
}

void dfs(int idx, int cur_s, int cur_b, int& ans, bool use_flag) {
    if (use_flag) {
        ans = std::min(ans, std::abs(cur_s - cur_b));
    }
    if (idx == n) {
        return;
    }
    /***
     * 如果check写在这里会出问题，递归到最后一层（idx == n），直接判断退出了，没有check，最后一层的信息会无效
     *  if (use_flag) {
     *      ans = std::min(ans, std::abs(cur_s - cur_b));
      * }
     */
    if (use_flag) {
        ans = std::min(ans, std::abs(cur_s - cur_b));
    }
    dfs(idx + 1, cur_s, cur_b, ans, use_flag | false);
    dfs(idx + 1, cur_s * foods[idx].s, cur_b + foods[idx].b, ans, use_flag | true);
}