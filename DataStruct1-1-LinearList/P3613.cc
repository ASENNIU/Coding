//
// Created by 13345 on 2023/10/16.
//

/***
 * 数据范围1e5，开二维数组的话就是1e5 * 1e5，必然MLE，而且不超过1e7个物品，大量空间浪费，而且查询只有1e5次
 * 所以问题就是优化二维数组的存储
 * 稀疏矩阵，根据坐标存储，且需要快速查询，所以上哈希
 * 两种方式
 * 1： std::pair，直接把坐标当做key
 * 2： 将二维坐标映射成1维, (i, j) -> i * C + j
 */

#include<cstdio>
#include<map>
using namespace std;
int n,q,p,k;
map<long long,int>b;
long long i,j;
int main()
{
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf("%d%d%d",&p,&i,&j);
        if(p==1)
        {
            scanf("%d",&k);
            b[i*1000000+j]=k;
        }
        else printf("%d\n",b[i*1000000+j]);
    }
    return 0;
}