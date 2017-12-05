#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define N 100020
using namespace std;

int a[N];
vector<pair<int, bool> > d;
vector<int> e[N];
int ans[N], f[N], s[N];
int r[N], c;

void Balance(int x)
{
    if(r[x] != c)
    {
        s[x] = 0;
        r[x] = c;
    }
    s[x] ++;

    return;
}

void HeavyChain(int x, int p)
{
    int i, u, v, t;

    for(i = 0, s[x] = 1, v = t = -1, f[x] = p;i < (signed)e[x].size();i ++)
        if((u = d[e[x].at(i)].first) != p)
        {
            HeavyChain(u, x);
            s[x] += s[u];
            if(v < s[u])
            {
                v = s[u];
                t =   i ;
            }
        }

    if(t != -1)
    {
        d[e[x].at(t)    ].second = true;
        d[e[x].at(t) ^ 1].second = true;
    }

    return;
}

void ActiveChain(int x, int p)
{
    int i, u;

    Balance(a[x]);
    for(i = 0;i < (signed)e[x].size();i ++)
        if((u = d[e[x].at(i)].first) != p)
            ActiveChain(u, x);

    return;
}

void ReverseChain(int x, int o)
{
    int i, u, p;

    while(true)
    {
        Balance(a[x]);
        for(i = 0, p = -1;i < (signed)e[x].size();i ++)
            if((u = d[e[x].at(i)].first) != o)
            {
                if(u == f[x])
                    p = i;
                else if(!d[e[x].at(i)].second)
                    ActiveChain(u, x);
            }
        ans[x] = s[a[x]];

        if(p == -1 || !d[e[x].at(p)].second)
            break;
        o = x, x = d[e[x].at(p)].first;
    }

    return;
}

void CountChain(int n)
{
    int i;

    for(i = 0, c = -1;i < n;i ++)
        if(e[i].size() == 1)
        {
            c = i;
            ReverseChain(i, i);
        }

    return;
}

void AddEdge(int u, int v)
{
    e[u].push_back(   d.size(        ));
    d   .push_back(make_pair(v, false));
    e[v].push_back(   d.size(        ));
    d   .push_back(make_pair(u, false));

    return;
}

int main()
{
    int n, u, v;
    int i;

    cin >> n;
    for(i = 0;i < n;i ++)
        cin >> a[i];
    for(i = 1;i < n;i ++)
    {
        cin >> u >> v;
        AddEdge(-- u, -- v);
    }

    HeavyChain(0, 0);
    CountChain(n   );

    for(i = 0;i < n;i ++)
        cout << ans[i] << ' ';
    cout << endl;
    
    return 0;
}
