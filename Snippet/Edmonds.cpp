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
bool u[N];
int p[N];

int AugmentEdmonds(int s, int t)
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

bool AdvanceEdmonds(int s, int t)
{
    int i, v;
    queue<int> q;

    memset(u, false, sizeof(u));
    for(q.push(s), u[s] = true;!q.empty();q.pop())
        for(i = 0;i < (signed)e[q.front()].size();i ++)
        {
            v = e[q.front()].at(i);
            if(!u[d.at(v).first] && d.at(v).second)
            {
                u[d.at(v).first] = true;
                p[d.at(v).first] = v   ;
                q.push(d.at(v).first);
            }
        }

    return u[t];
}

int Edmonds(int s, int t)
{
    int k;

    for(k = 0;AdvanceEdmonds(s, t);k += AugmentEdmonds(s, t))
        ;

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
        AddEdge(u, v, w);
    }
    cout << Edmonds(0, n - 1) << endl;

    return 0;
}
