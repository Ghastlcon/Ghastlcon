#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define N 120
#define INFINITE 999999999
using namespace std;

typedef struct
{
    int v;
    int w;
    int c;
}EDGE;

vector<EDGE> d;
vector<int> e[N];
bool u[N];
int l[N], p[N];

int AugmentKarp(int s, int t)
{
    int x, k;

    for(x = t, k = INFINITE;x != s;x = d.at(p[x] ^ 1).v)
        k = min(k, d.at(p[x]).w);
    for(x = t              ;x != s;x = d.at(p[x] ^ 1).v)
    {
        d.at(p[x]    ).w -= k;
        d.at(p[x] ^ 1).w += k;
    }

    return k;
}

bool AdvanceKarp(int s, int t)
{
    int i, v;
    queue<int> q;

    memset(u, false, sizeof(u));
    for(i = 0;i < N;i ++)
        l[i] = INFINITE;

    for(q.push(s), u[s] = true, l[s] = 0;!q.empty();q.pop())
    {
        u[q.front()] = false;
        for(i = 0;i < (signed)e[q.front()].size();i ++)
        {
            v = e[q.front()].at(i);
            if(l[d.at(v).v] > l[q.front()] + d.at(v).c && d.at(v).w)
            {
                l[d.at(v).v] = l[q.front()] + d.at(v).c;
                p[d.at(v).v] = v;
                if(!u[d.at(v).v])
                {
                    u[d.at(v).v] = true;
                    q.push(d.at(v).v);
                }
            }
        }
    }

    return l[t] != INFINITE;
}

pair<int, int> Karp(int s, int t)
{
    pair<int, int> k;
    int p;

    for(k = make_pair(0, 0);AdvanceKarp(s, t);)
    {
        p = AugmentKarp(s, t);
        k = make_pair(k.first + p, k.second + p * l[t]);
    }

    return k;
}

void AddEdge(int u, int v, int w, int c)
{
    e[u].push_back(d.size(        ));
    d   .push_back((EDGE){v, w,  c});
    e[v].push_back(d.size(        ));
    d   .push_back((EDGE){u, 0, -c});

    return;
}

int main()
{
    int n, m, u, v, w, c;
    pair<int, int> k;

    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v >> w >> c;
        AddEdge(u, v, w, c);
    }
    
    k = Karp(0, n - 1);
    cout << k.first << ' ' << k.second << endl;

    return 0;
}
