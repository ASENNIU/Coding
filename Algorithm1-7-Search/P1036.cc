//
// Created by 13345 on 2023/9/27.
//

#include <cstdio>
#include <cmath>
#define N 25

int n, k;
int a[N];
void dfs(int sum, int cur_idx, int cur_used, int& ans);
bool check(int x);

int main()
{
    scanf("%d %d", &n, &k);
    for (unsigned i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int ans = 0;
    dfs(0, 0, 0, ans);
    printf("%d\n", ans);

    return 0;
}

void dfs(int sum, int cur_idx, int cur_used, int& ans) {
    if (cur_used == k) {
        if (check(sum)) {
            ++ans;
        }
//        printf("check sum false, cur sum: %d\n", sum);
        return;
    }
    if (cur_idx == n) {
        return;
    }

    dfs(sum + a[cur_idx], cur_idx + 1, cur_used + 1, ans);
    dfs(sum, cur_idx + 1, cur_used, ans);
}

bool check(int x) {
    if (x == 1 || x == 2 || x == 3) {
        return true;
    }
    int tmp = sqrt(x);
    for (int i = 2; i <= tmp; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}