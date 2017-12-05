#include <iostream>
#include <algorithm>
#define N 120
#define INFINITE 999999999
using namespace std;

int f[N][N];

int Dijkstra(int n, int s, int t)
{
    int d[N];
    bool u[N] = { false };
    int i, j, k, p;
    
    for(i = 0, u[s] = true;i < n;i ++)
        d[i] = f[s][i];
    for(i = 0;i < n - 1;i ++)
    {
        for(j = 0, p = INFINITE;j < n;j ++)
            if(!u[j] && d[j] < p)
                p = d[k = j];
        for(j = 0, u[k] = true;j < n;j ++)
            d[j] = min(d[j], d[k] + f[k][j]);
    }
    
    return d[t];
}

int main()
{
    int n, m;
    int u, v, w;
    
    for(u = 0;u < N;u ++)
        for(v = 0;v < N;v ++)
            f[u][v] = (u == v ? 0 : INFINITE);
    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v >> w;
        f[u][v] = w;
    }

    cout << Dijkstra(n, 0, n - 1) << endl;
    
    return 0;
}
