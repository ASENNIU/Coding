//
// Created by 13345 on 2023/11/22.
//

#include <cstdio>
#include <algorithm>

#define MAXN 500005

struct edge{
    int to, pre;
}edges[MAXN << 1];

int depth[MAXN], head[MAXN], cnt, fa[MAXN][22], lg[MAXN];

void add(int u, int v) {
    edges[++cnt].to = v;
    edges[cnt].pre = head[u];
    head[u] = cnt;
}

void dfs(int x, int pre) {
    depth[x] = depth[pre] + 1;
    fa[x][0] = pre;
    for (int i = 1; i <= lg[depth[x]]; ++i) {
        // fa[x][0] = pre 2^0级先祖
        // fa[x][1] = fa[pre][0] 也就是pre的上一个节点，相对于x而言是隔了2个，就是第2^1级先祖
        // 同理fa[x][2] = fa[fa[x][1]][1] 由上面可知，fa[x][1]是隔离2个节点，fa[fa[x][1]][1]就是前面第2个节点的前面2个节点，就是
        // 相对于x隔了4个节点，即2^2级先祖
        fa[x][i] = fa[fa[x][i-1]][i-1];
    }
    for (int i = head[x]; i; i = edges[i].pre) {
        int v = edges[i].to;
        if (v != pre) {
            dfs(v, x);
        }
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        std::swap(x, y);
    }
    //lg[dep[x]-dep[y]]表示log(dep[x]-dep[y])+1,再减去1
    //让x往上跳2^log([dep[x]-dep[y])层
    /*
    倍增
    是不是任何一个正整数都能被一些2的n次方加起来?
    答案是:可以的，因为每个数字都可以用二进制表示
    十进制：16=16	     15=8+4+2+1	         10=8+2	       5=4+1	        ...
    二进制：10000=10000  1111=1000+100+10+1	 1010=1000+10  101=100+1        ...
    所以倍增LCA的意思就是: 每次以2的k次方跳跃!!

    （以上大致改编于arfa大佬的
    [博客](https://www.luogu.org/blog/acking/solution-p3379)）

    这里就要用到lg数组判断x要往上跳多少
    Q1：为什么要一步一步以2的k次方跳跃？
    因为fa[x][k]表示的是x的2^N层上的祖先,所以不能一步跳到上k（k为任意数）层的
    让x往上跳(2^k1+2^k2+2^k3+......)层 才能让x和y达到同一高度
    Q2：为什么x可以一步一步跳上y那一层？
    设 k=log([dep[x]-dep[y])
    k是向下取整，例如dep[x]-dep[y]=5=(101)2=(100)2+(1)2（二进制表示）
    那么就要往上跳2次，分别跳 (100)2 、 (1)2 层
    （所以，log(x)也可以表示x二进制除了最高位的1之外都去掉的形式）
    往上跳了一次以后，dep[x]-dep[y]=(101)2-(100)2=(1)2，再往上跳(1)2层就可以了
    x一步一步逼近y那一层，dep[x]-dep[y]一步一步减小，就能达到了
    */
    while (depth[x] > depth[y]) {
        x = fa[x][lg[depth[x] - depth[y]] - 1];
    }
    if (x == y) return x;
    // 注意:层数=......,8,4,2,1 设p=2^k
    // 这里相当于自上而下遍历，最上面的指向根节点，这里就是lg[i] = logi + 1的意义，一定会指向根节点
    // 然后找到第一个不相等的节点
    for (int k = lg[depth[x] - 1]; k >= 0; --k) {
        if (fa[x][k] != fa[y][k]) {
            x = fa[x][k];
            y = fa[y][k];
        }
    }

    return fa[x][0];
}

int main()
{
    int n, m, s, x, y;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%d %d", &x, &y);
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; ++i) {
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    }
    dfs(s, 0);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }

    return 0;
}