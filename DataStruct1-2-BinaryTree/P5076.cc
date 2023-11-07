//
// Created by 13345 on 2023/11/7.
//

#include <cstdio>

const int INF = 0x7fffffff;
int count;
struct node {
    int val, ls, rs, siz, cnt;
}tree[1000010];

void add(int idx, int val);
int query_front(int idx, int val, int ans);
int query_next(int idx, int val, int ans);
int query_rank(int idx, int rank);
int query_val(int idx, int val);

int main()
{
    int n, opt, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &opt, &x);
        switch (opt) {
            case 1:
                printf("%d\n", query_val(1, x) + 1);
                break;
            case 2:
                printf("%d\n", query_rank(1, x));
                break;
            case 3:
                printf("%d\n", query_front(1, x, -INF));
                break;
            case 4:
                printf("%d\n", query_next(1, x, INF));
                break;
            case 5:
                if (count == 0) {
                    tree[++count].val = x;
                    tree[count].cnt = tree[count].siz = 1;
                } else {
                    add(1, x);
                }
                break;
        }
    }
//    for (int i = 1; i <= count; ++i) {
////        printf("count: %d, val: %d, ls: %d, rs: %d, size: %d, cnt: %d\n", i, tree[i].val, tree[i].ls, tree[i].rs, tree[i].siz, tree[i].cnt);
//    }
    return 0;
}

void add(int idx, int val) {
    tree[idx].siz++;
    if (tree[idx].val == val) {
        tree[idx].cnt++;
        return;
    } else if (tree[idx].val > val) {
        if (tree[idx].ls != 0) {
            add(tree[idx].ls, val);
        } else {
            tree[++count].val = val;
            tree[count].siz = tree[count].cnt = 1;
            tree[idx].ls = count;
        }
    } else {
        if (tree[idx].rs != 0) {
            add(tree[idx].rs, val);
        } else {
            tree[++count].val = val;
            tree[count].siz = tree[count].cnt = 1;
            tree[idx].rs = count;
        }
    }
}

int query_front(int idx, int val, int ans) {
    if (tree[idx].val>=val)
    {
        if (tree[idx].ls==0)
            return ans;
        else
            return query_front(tree[idx].ls,val,ans);
    }
    else
    {
        if (tree[idx].rs==0)
            return tree[idx].val;
        return query_front(tree[idx].rs,val,tree[idx].val);
    }

}
int query_next(int idx, int val, int ans) {
    if (tree[idx].val <= val) {
        if (tree[idx].rs == 0) {
            return ans;
        } else {
            query_next(tree[idx].rs, val, ans);
        }
    } else {
        if (tree[idx].ls == 0) {
            return (tree[idx].val > val) ? tree[idx].val : ans;
        } else {
            if (tree[idx].cnt != 0) {
                return query_next(tree[idx].ls, val, tree[idx].val);
            } else {
                return query_next(tree[idx].ls, val, ans);
            }
        }
    }

}
int query_rank(int idx, int rank) {
    if (idx == 0) return INF;
    if (tree[tree[idx].ls].siz >= rank) return query_rank(tree[idx].ls, rank);
    if (tree[tree[idx].ls].siz + tree[idx].cnt >= rank) return tree[idx].val;
    return query_rank(tree[idx].rs, rank - (tree[tree[idx].ls].siz + tree[idx].cnt));
}
int query_val(int idx, int val) {
    if (idx == 0) return 0;
    if (tree[idx].val == val) return tree[tree[idx].ls].siz;
    if (tree[idx].val > val) return query_val(tree[idx].ls, val);
    return query_val(tree[idx].rs, val) + tree[tree[idx].ls].siz + tree[idx].cnt;
}


