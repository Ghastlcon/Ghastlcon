#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define N 120
using namespace std;

vector<pair<int, int> > e[N];
vector<pair<int, int> > q[N];
pair<int, int> l[N];
int f[N], d[N], s[N];
bool o[N];

int GetFUFS(int x)
{
    int i = x, t;

    while(f[i] != i)
        i = f[i];
    while(x != i)
    {
        t = f[x];
        f[x] = i;
        x = t;
    }

    return i;
}

void InitLCA(int x, int p)
{
    int i;

    o[x] = true;
    for(i = 0;i < (signed)e[x].size();i ++)
        if(e[x].at(i).first != p)
        {
            s[e[x].at(i).first] = s[x] + e[x].at(i).second;
            InitLCA(e[x].at(i).first, x);
            f[e[x].at(i).first] = x;
        }

    for(i = 0;i < (signed)q[x].size();i ++)
        if(o[q[x].at(i).first])
            d[q[x].at(i).second] = GetFUFS(q[x].at(i).first);

    return;
}

int DistanceLCA(int x)
{
    return s[l[x].first] + s[l[x].second] - 2 * s[d[x]];
}

int main()
{
    int n, q;
    int u, v, w;

    cin >> n >> q;
    while(n --> 1)
    {
        cin >> u >> v >> w;
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }
    for(u = 0;u < q;u ++)
    {
        cin >> l[u].first >> l[u].second;
        ::q[l[u].first].push_back(make_pair(l[u].second, u));
        ::q[l[u].second].push_back(make_pair(l[u].first, u));
    }

    for(u = 0;u < N;u ++)
        f[u] = u;
    InitLCA(0, 0);
    for(u = 0;u < q;u ++)
        cout << DistanceLCA(u) << endl;

    return 0;
}
