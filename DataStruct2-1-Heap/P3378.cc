//
// Created by 13345 on 2023/12/19.
//

#include <cstdio>

#define N 1000005

void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

int heap[N], siz;
void push(int x) {
    heap[++siz] = x;
    int now = siz;
    while (now) {
        int next = now >> 1;
        if (heap[next] > heap[now]) {
            swap(heap[next], heap[now]);
        } else
            break;
        now = next;
    }
}

void pop() {
    swap(heap[siz], heap[1]);
    --siz;
    int now = 1;
    while ((now << 1) <= siz) {
        int next = now << 1;
        // 堆中某一节点的左右子节点，其大小关系并不确定
        if (next + 1 <= siz && heap[next+1] < heap[next]) ++next;
        if (heap[next] < heap[now]) swap(heap[now], heap[next]);
        else break;
        now = next;
    }
}
int top() {
    return heap[1];
}

int main()
{
    int n, op, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                printf("%d\n", top());
                break;
            case 3:
                pop();
                break;
        }
    }
    return 0;
}



