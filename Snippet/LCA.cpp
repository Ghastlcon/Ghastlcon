#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define N 120
#define M 8
using namespace std;

vector<pair<int, int> > e[N];
int d[N], s[N], f[N][M];

void InitLCA(int x, int p)
{
    static int t;
    int i;

    d[x] = ++ t;
    for(f[x][0] = p, i = 1;i < M;i ++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for(i = 0;i < (signed)e[x].size();i ++)
        if(e[x].at(i).first != p)
        {
            s[e[x].at(i).first] = s[x] + e[x].at(i).second;
            InitLCA(e[x].at(i).first, x);
        }

    return;
}

int GetLCA(int u, int v)
{
    int i;

    if(u == v)
        return u;
    if(d[u] > d[v])
        swap(u, v);

    for(i = M - 1;i > -1;i --)
        if(d[f[v][i]] > d[u])
            v = f[v][i];

    return f[v][0];
}

int DistanceLCA(int u, int v)
{
    return s[u] + s[v] - 2 * s[GetLCA(u, v)];
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

    InitLCA(0, 0);
    while(q --)
    {
        cin >> u >> v;
        cout << DistanceLCA(u, v) << endl;
    }

    return 0;
}
