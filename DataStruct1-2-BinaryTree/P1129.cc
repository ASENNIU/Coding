//
// Created by 13345 on 2023/11/3.
//

/***
 * 前序和后续遍历在某一节点只有一个子节点时，无法确定其中序遍历。
 * 只有一个儿子 的节点 才会在知道 前序后序 的情况下有不同的中序遍历，所以将题目转化成找 只有一个儿子的节点个数。
 * 可以很容易的找出这类节点在前序后序中出现的规律。（前序中出现AB，后序中出现BA，则这个节点只有一个儿子）
 * 每个这类节点有两种中序遍历（及儿子在左，儿子在右）根据乘法原理中序遍历数为 2^节点个数
 * 数组可以越界，其行为是未知的
 */

#include <cstring>
#include <cstdio>

long long ans = 0;
char str1[255];
char str2[255];


int main() {
    scanf("%s", str1);
    scanf("%s", str2);
    for (unsigned int i = 0; i < strlen(str1) - 1; ++i) {
        for (unsigned int j = 1; j < strlen(str2); ++j) {
            if (str1[i] == str2[j] && str1[i+1] == str2[j-1] ) {
                ++ans;
            }
        }
    }
    printf("%lld\n", 1 << ans);

    return 0;
}


