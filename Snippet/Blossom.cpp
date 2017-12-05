#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 120
using namespace std;

vector<int> e[N];
int f[N], g[N], h[N], c;
int p[N], u[N], o[N];

int GetUFS(int x)
{
    int i, t;

    for(i = x;f[i] != i;i = f[i])
        ;
    while(x != i)
    {
        t = f[x];
        f[x] = i;
        x = t;
    }

    return i;
}

int GetLCA(int x, int y)
{
    static int k = 0;

    for(k ++, x = GetUFS(x), y = GetUFS(y);;swap(x, y))
        if(x)
        {
            if(h[x] == k)
                break;
            h[x] = k;
            x = GetUFS(p[o[x]]);
        }

    return x;
}

void Bloom(int x, int y, int l)
{
    while(GetUFS(x) != l)
    {
        p[x] = y;
        if(u[o[x]] == 1)
            u[g[c ++] = o[x]] = 0;

        if( f[  x ] ==   x )
            f[  x ] = l;
        if( f[o[x]] == o[x])
            f[o[x]] = l;

        y = o[x];
        x = p[y];
    }

    return;
}

bool Match(int x)
{
    int i, j, t, v;

    for(i = 0;i < N;i ++)
        f[i] = i;

    memset(u, -1, sizeof(u));
    u[g[c = 0] = x] = 0;

    for(i = 0, c = 1;i < c;i ++)
        for(j = 0;j < (signed)e[g[i]].size();j ++)
            if(u[v = e[g[i]].at(j)] == -1)
            {
                p[v] = g[i];
                u[v] = 1   ;

                if(!o[v])
                {
                    for(t = v, v = g[i];v;t = i, v = p[t])
                    {
                        i = o[v];
                        o[v] = t;
                        o[t] = v;
                    }

                    return true;
                }
                u[g[c ++] = o[v]] = 0;
            }
            else if(!u[v] && GetUFS(v) != GetUFS(g[i]))
            {
                Bloom(v, g[i], t = GetLCA(v, g[i]));
                Bloom(g[i], v, t                  );
            }

    return false;
}

int Blossom(int n)
{
    int i, v;

    for(i = 1, v = 0;i <= n;i ++)
        if(!o[i])
            v += Match(i);

    return v;
}

int main()
{
    int n, m, u, v;
    int i;

    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cout << Blossom(n) << endl;
    
    return 0;
}