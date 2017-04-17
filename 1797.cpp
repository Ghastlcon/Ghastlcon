#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define N 50
#define F 10
#define INFINITE 999999999
using namespace std;

int n, f;
int p[N][F]; //在第i个小岛买第j个公司的票的花费
vector<pair<int, int> > e[F]; //e[i]保存第i个公司有的船票（pair保存起始点和结束点）

queue<pair<int, int> > q; //SPFA队列，first表示当前点，second表示当前集合
int d[N][1 << F], c[1 << F];
//d[i][j]表示到达第i个小岛，剩余公司集合为j，最少花费
//c[i]表示i中1的个数

int Count(int x) //统计x中1的个数
{
    int i, j;

    for(i = j = 0;i < F;i ++)
        j += !!(x & (1 << i));

    return j;
}

void SPFA()
{
    int i, j;
    pair<int, int> o;

    while(!q.empty()) //清空队列
        q.pop();
    memset(d, 0, sizeof(d));

    for(i = 0;i < n;i ++)
        for(j = 0;j < (1 << f);j ++)
            d[i][j] = INFINITE; //距离初始值：全部∞
    d[0][0] = 0; //开始在第0个小岛，没有票

    for(q.push(make_pair(0, 0));!q.empty();)
    {
        o = q.front(); //队首元素：当前状态
        q.pop();

        for(i = 0;i < f;i ++) //枚举公司（买或者用）
        {
            //BUY ONE
            if(!(o.second & (1 << i)) && c[o.second | (1 << i)] < 4 && d[o.first][o.second | (1 << i)] > p[o.first][i] + d[o.first][o.second])
            //如果 当前集合里面没有这张票 并且 买了这张票之后总数不超过3个 并且 可以松弛别人
            {
                d[o.first][o.second | (1 << i)] = p[o.first][i] + d[o.first][o.second];
                q.push(make_pair(o.first, o.second | (1 << i)));
                //松弛入队
            }

            //GO YOU
            if(o.second & (1 << i)) //首先要有票才能走→_→
                for(j = 0;j < (signed)e[i].size();j ++) //枚举这个公司有的票
                    if(e[i].at(j).first == o.first && d[e[i].at(j).second][o.second & (~(1 << i))] > d[o.first][o.second])
                    //如果 这张票的起点在当前点 并且 可以松弛别人
                    {
                        d[e[i].at(j).second][o.second & (~(1 << i))] = d[o.first][o.second];
                        q.push(make_pair(e[i].at(j).second, o.second & (~(1 << i))));
                        //松弛入队
                    }
        }
    }

    return;
}

int main()
{
    int r, u, v;
    int i, j, k;

    freopen("1797.in" , "r", stdin );
    freopen("1797.out", "w", stdout);

    for(i = 0;i < (1 << F);i ++)
        c[i] = Count(i); //预处理
    
    cin >> r;
    while(r --)
    {
        cin >> n >> f;
        for(i = 0;i < f;i ++)
        {
            e[i].clear(); //清空vector
            cin >> k;
            for(j = 0;j < k;j ++)
            {
                cin >> u >> v;
                e[i].push_back(make_pair(u, v)); //第i个公司有u→v的船票
            }
        }
        for(i = 0;i < n;i ++)
            for(j = 0;j < f;j ++)
                cin >> p[i][j];

        SPFA(); //SPFA
        for(i = 1;i < n;i ++)
            cout << (d[i][0] == INFINITE ? -1 : d[i][0]) << ' ';
        cout << endl;
    }
    
    return 0;
}
