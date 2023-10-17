//
// Created by 13345 on 2023/10/17.
//

#include<cstdio>
#include<queue>

using namespace std;
int n, t, m, x;
int temp_nation[1000005];
int ans;

struct node
{
    int s, t;
    //made in china
};
queue<node>ship;
node h;

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d",&t,&m);
        while(!ship.empty())//只要还有人就对队列进行检查
        {
            h = ship.front();//循环取队头（由于时间是单调递增的）
            if(h.t+86400<=t)//如果在时间外（不符合条件），则对答案和队列进行更新（删减）
            {
                temp_nation[h.s]--;//这个国籍人数总数减1（因为这不是24小时内的人）
                if(temp_nation[h.s]==0)   ans--;//如果这个国籍没有人了，则答案数减1（之前记过）
                ship.pop();//把这个被时代所淘汰的人给丢掉
                continue;//因为是单调递增的，所以有可能还会有，继续去找
            }
            break;//如果现在这个在24小时内，后面的肯定也符合条件，直接退出
        }
        for(int j = 1 ; j<= m; ++j) //查完前面后，我们就对这只本身的船进行统计
        {
            scanf("%d",&x);//输入国籍
            h.s = x, h.t = t;//存进结构体
            ship.push(h);//把这个人（结构体）给存进队列
            temp_nation[x]++;//这个国籍的人加1（桶排思想）
            if(temp_nation[x]==1)  ans++;//如果这个国籍是！相对！第一次出现，那么就算上他
        }
        printf("%d\n",ans);//模拟完了以后就输出答案
    }
    return 0;
}


