//
// Created by 13345 on 2023/9/21.
//

#include <queue>
#include <set>
#include <stdio.h>
#include <vector>

#define N 50005
int a[N];

struct jump {
    int distance, start, end;
    jump(int d = 0, int s = 0, int e = 0) : distance(d), start(s), end(e) {}
};


int main()
{
    int l, n, m;

    auto cmp = [](const jump& a, const jump& b) { return  a.distance > b.distance; };
    std::priority_queue<jump, std::vector<jump>, decltype(cmp)> p_queue(cmp);
    std::set<int> moved;
    scanf("%d %d %d", &l, &n, &m);
    if (m == n) {
        printf("%d\n", l);
        return 0;
    }
    for (unsigned i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        p_queue.emplace(a[i] - a[i-1], i - 1, i);
    }
    a[n+1] = l;
    p_queue.emplace(a[n+1] - a[n], n, n + 1);
    while (m) {
        jump j = p_queue.top();
        p_queue.pop();
        if (moved.find(j.start) != moved.end() | moved.find(j.end) != moved.end()) {
            continue;
        }
        jump new_j;
        int move;
        if (j.start == 0) {
            new_j.start = j.start;
            int right = j.end + 1;
            while (right < n + 1 && moved.find(right) != moved.end()) ++right;
            new_j.end = right;
            new_j.distance = a[right] - a[new_j.start];
            moved.insert(j.end);
            move = j.end;
        } else if (j.end == n + 1) {

            int left = j.start - 1;
            while (left > 0 && moved.find(left) != moved.end()) --left;
            new_j.start = left;
            new_j.end = n + 1;
            new_j.distance = l - a[left];
            moved.insert(j.start);
            move = j.start;
        } else {
            int left = j.start - 1;
            while (left > 0 && moved.find(left) != moved.end()) --left;
            int right = j .end + 1;
            while (right < n + 1 && moved.find(right) != moved.end()) ++right;
            int l_jump = a[j.start] - a[left];
            int r_jump = a[right] - a[j.end];
            if (l_jump > r_jump) {
                new_j.distance = r_jump + j.distance;
                new_j.start = j.start;
                new_j.end = right;
                moved.insert(j.end);
                move = j.end;
            } else {
                new_j.distance = l_jump + j.distance;
                new_j.start = left;
                new_j.end = j.end;
                moved.insert(j.start);
                move = j.end;
            }
        }
        p_queue.push(new_j);
        --m;
//        printf("move %d, pop (%d, %d, %d), push (%d, %d, %d)\n",
//               move, j.distance, j.start, j.end, new_j.distance, new_j.start, new_j.end);

    }

    while (!p_queue.empty()) {
        jump j = p_queue.top();
        if (moved.find(j.start) != moved.end() | moved.find(j.end) != moved.end()) {
            p_queue.pop();
            continue;
        }
        printf("%d\n", j.distance);
        break;
    }

    return 0;
}
