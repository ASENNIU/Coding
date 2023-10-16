//
// Created by 13345 on 2023/10/16.
//


/***
 * 双向链表支持快速插入删除
 * 用数组存储元素到链表迭代器的映射，插入并不会使迭代器失效
 */

#include <cstdio>
#include <list>

#define N 100005

using Iter = std::list<int>::iterator;
std::list<int> queue_list;
Iter pos[N];
bool is_removed[N];
int main()
{
    int n, m, k, p;
    scanf("%d", &n);
    queue_list.push_front(1);
    pos[1] = queue_list.begin();
    for (int i = 2; i <= n; ++i) {
        scanf("%d %d", &k, &p);
        if (p == 0) {
            pos[i] = queue_list.insert(pos[k], i);
        } else {
            Iter next_pos = std::next(pos[k]);
            pos[i] = queue_list.insert(next_pos, i);
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (is_removed[tmp]) {
            continue;
        }
        queue_list.erase(pos[tmp]);
        is_removed[tmp] = true;
    }
    for (int it : queue_list) {
        printf("%d ", it);
    }

    return 0;
}