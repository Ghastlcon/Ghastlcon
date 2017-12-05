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
int l[N], u[N], p[N], r[N];

void LevelISAP(int t)
{
    int i, v;
    queue<int> q;

    for(q.push(t), u[t] = 1;!q.empty();q.pop())
        for(i = 0;i < (signed)e[q.front()].size();i ++)
            {
                v = e[q.front()].at(i);
                if(!u[d.at(v).first])
                {
                    u[d.at(v).first] =                1;
                    l[d.at(v).first] = l[q.front()] + 1;
                    q.push(d.at(v).first);
                }
            }

    return;
}

int AugmentISAP(int s, int t)
{
    int x, k;

    for(x = t, k = INFINITE;x != s;x = d.at(p[x] ^ 1).first)
        k = min(k, d.at(p[x]).second);
    for(x = t              ;x != s;x = d.at(p[x] ^ 1).first)
    {
        d.at(p[x]    ).second -= k;
        d.at(p[x] ^ 1).second += k;
    }

    return k;
}

bool AdvanceISAP(int &x)
{
    int i, v;

    for(i = r[x];i < (signed)e[x].size();i ++)
    {
        v = e[x].at(i);
        if(l[x] == l[d.at(v).first] + 1 && d.at(v).second)
        {
            r[x                ] = i;
            p[x = d.at(v).first] = v;

            return true;
        }
    }

    return false;
}

bool RetreatISAP(int &x, int s, int t)
{
    int i, v;

    for(i = 0;i < (signed)e[x].size();i ++)
        if(d.at(v = e[x].at(i)).second)
            t = min(t, l[d.at(v).first]);
    if(!(-- u[l[x]]))
        return false;

    u[l[x] = t + 1]  ++;
    r[  x         ] = 0;
    if(x != s)
        x = d.at(p[x] ^ 1).first;

    return true;
}

int ISAP(int s, int t)
{
    int i, x, k;

    LevelISAP(t);
    memset(u, 0, sizeof(u));
    for(i = 0;i <= t;i ++)
        u[l[i]] ++;

    for(x = s, k = 0;l[s] <= t;)
    {
        if(x == t)
            k += AugmentISAP(x = s, t);
        if(!AdvanceISAP(x) && !RetreatISAP(x, s, t))
            break;
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
    int i;

    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v >> w;
        AddEdge(u, v, w);
    }
    cout << ISAP(0, n - 1) << endl;

    return 0;
}
