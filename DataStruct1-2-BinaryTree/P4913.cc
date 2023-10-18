//
// Created by 13345 on 2023/10/18.
//

#include <cstdio>

#define MAXN 1000005

struct node {
    int left, right;
    node(int l, int r) : left(l), right(r) {}
    node() {
        left = -1;
        right = -1;
    }
};

node tree[MAXN];

void dfs(int idx, int depth);
int ans = 0;

int main()
{
    int n, left, right;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &tree[i].left, &tree[i].right);
    }
    dfs(1, 1);
    printf("%d\n", ans);

    return 0;
}

void dfs(int idx, int depth) {
    ans = ans > depth ? ans : depth;
    if (tree[idx].left != 0) {
        dfs(tree[idx].left, depth + 1);
    }
    if (tree[idx].right != 0) {
        dfs(tree[idx].right, depth + 1);
    }
}
