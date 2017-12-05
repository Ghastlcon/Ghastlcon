#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define N 120
#define INFINITE 999999999
using namespace std;

vector<pair<int, int> > d;
vector<int> e[N];
int l[N], r[N];

bool LevelDinic(int s, int t)
{
    int i, v;
    queue<int> q;

    memset(l, 0, sizeof(l));
    for(q.push(s), l[s] = 1;!q.empty();q.pop())
        for(i = 0;i < (signed)e[q.front()].size();i ++)
        {
            v = e[q.front()].at(i);
            if(!l[d.at(v).first] && d.at(v).second)
            {
                l[d.at(v).first] = l[q.front()] + 1;
                q.push(d.at(v).first);
            }
        }

    return l[t];
}

int BlockDinic(int x, int v, int t)
{
    int k, f;

    if(x == t || !v)
        return v;

    for(f = 0;r[x] < (signed)e[x].size();r[x] ++)
    {
        k = e[x].at(r[x]);
        if(l[x] + 1 == l[d.at(k).first] && (f = BlockDinic(d.at(k).first, min(v, d.at(k).second), t)) > 0)
        {
            d.at(k    ).second -= f;
            d.at(k ^ 1).second += f;
            break;
        }
    }

    return f;
}

int Dinic(int s, int t)
{
    int v, k;

    for(k = 0;LevelDinic(s, t);)
    {
        memset(r, 0, sizeof(r));
        while(v = BlockDinic(s, INFINITE, t), v)
            k += v;
    }

    return k;
}

void AddEdge(int u, int v, int w)
{
    e[u].push_back(   d.size(    ));
    d   .push_back(make_pair(v, w));
    e[v].push_back(   d.size(    ));
    d   .push_back(make_pair(u, 0));

    return;
}

int main()
{
    int n, m, u, v, w;

    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v >> w;
        e[-- u].push_back(   d.size(       ));
        d      .push_back(make_pair(-- v, w));
        e[   v].push_back(   d.size(       ));
        d      .push_back(make_pair(   u, 0));
    }
    cout << Dinic(0, n - 1) << endl;

    return 0;
}
