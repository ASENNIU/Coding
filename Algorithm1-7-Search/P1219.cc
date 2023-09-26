//
// Created by 13345 on 2023/9/26.
//

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

#define N 13

bool column[N];
bool diag_1[N * 2];
bool diag_2[N * 2];

void dfs(int cur_row, int total, std::vector<int>& vec, std::vector<std::vector<int> >& ans);

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int> > ans;
    for (int i = 0; i < n; ++i) {
        memset(column, 0, sizeof(column));
        memset(diag_1, 0, sizeof(diag_1));
        memset(diag_2, 0, sizeof(diag_2));
        std::vector<int> vec{i};
        column[i] = true;
        diag_1[i] = true;
        diag_2[n-1-0+i] = true;
        dfs(1, n, vec, ans) ;

    }

    std::sort(ans.begin(), ans.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
        for (unsigned j = 0; j < a.size(); ++j) {
            if (a[j] != b[j]) {
                return a[j] < b[j];
            }
        }
        return false;
    });

    for (unsigned i = 0; i < 3; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            printf("%d ", ans[i][j] + 1) ;
        }
        printf("\n");
    }
    printf("%d\n", ans.size());
    return 0;
}

void dfs(int cur_row, int total, std::vector<int>& vec, std::vector<std::vector<int> >& ans) {
    if (cur_row == total) {
        ans.push_back(vec);
        return;
    }

    for (int j = 0; j < total; ++ j) {
        if (!column[j] && !diag_1[cur_row+j] && !diag_2[total-1-cur_row+j]) {
            vec.push_back(j);
            column[j] = true;
            diag_1[cur_row+j] = true;
            diag_2[total-1-cur_row+j] = true;

            dfs(cur_row + 1, total, vec, ans);

            vec.pop_back();
            column[j] = false;
            diag_1[cur_row+j] = false;
            diag_2[total-1-cur_row+j] = false;
        }
    }
    return;
}

