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
int p[N][F];
vector<pair<int, int> > e[F];

queue<pair<int, int> > q;
int d[N][1 << F], u[N][1 << F];

int Count(int x)
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

    while(!q.empty())
        q.pop();
    memset(d, 0, sizeof(d));
    for(i = 0;i < n;i ++)
        for(j = 0;j < (1 << f);j ++)
            d[i][j] = INFINITE;
    d[0][0] = 0;

    for(q.push(make_pair(0, 0));!q.empty();)
    {
        o = q.front();
        q.pop();

        for(i = 0;i < f;i ++)
        {
            if(!(o.second & (1 << i)) && Count(o.second | (1 << i)) < 4 && d[o.first][o.second | (1 << i)] > p[o.first][i] + d[o.first][o.second])
            {
                d[o.first][o.second | (1 << i)] = p[o.first][i] + d[o.first][o.second];
                q.push(make_pair(o.first, o.second | (1 << i)));
            }
            if(o.second & (1 << i))
                for(j = 0;j < (signed)e[i].size();j ++)
                    if(e[i].at(j).first == o.first && d[e[i].at(j).second][o.second & (~(1 << i))] > d[o.first][o.second])
                    {
                        d[e[i].at(j).second][o.second & (~(1 << i))] = d[o.first][o.second];
                        q.push(make_pair(e[i].at(j).second, o.second & (~(1 << i))));
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
    
    cin >> r;
    while(r --)
    {
        cin >> n >> f;
        for(i = 0;i < f;i ++)
        {
            e[i].clear();
            cin >> k;
            for(j = 0;j < k;j ++)
            {
                cin >> u >> v;
                e[i].push_back(make_pair(u, v));
            }
        }
        for(i = 0;i < n;i ++)
            for(j = 0;j < f;j ++)
                cin >> p[i][j];

        SPFA();
        for(i = 1;i < n;i ++)
            cout << (d[i][0] == INFINITE ? -1 : d[i][0]) << ' ';
        cout << endl;
    }
    
    return 0;
}
