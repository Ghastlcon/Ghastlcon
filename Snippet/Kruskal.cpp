#include <iostream>
#include <algorithm>
#define N 120
using namespace std;

typedef struct _EDGE
{
    int u;
    int v;
    int w;
    
    bool operator<(const _EDGE &that) const
    {
        return w < that.w;
    }
}EDGE;

EDGE e[N * N];
int f[N];

int GetUFS(int x)
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

void MergeUFS(int x, int y)
{
    int p, q;
    
    p = GetUFS(x);
    q = GetUFS(y);
    if(p != q)
        f[p] = q;
    
    return;
}

int Kruskal(int n, int m)
{
    int i, j, u;

    for(i = 0;i < n;i ++)
        f[i] = i;
    sort(e, e + m);
    
    for(i = j = u = 0;i < m && j < n - 1;i ++)
        if(GetUFS(e[i].u) != GetUFS(e[i].v))
        {
            MergeUFS(e[i].u, e[i].v);
            j ++;
            u += e[i].w;
        }

    return u;
}

int main()
{
    int n, m;
    int i;
    
    cin >> n >> m;
    for(i = 0;i < m;i ++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    cout << Kruskal(n, m) << endl;

    return 0;
}
