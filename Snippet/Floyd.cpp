#include <iostream>
#include <algorithm>
#define N 120
#define INFINITE 999999999
using namespace std;

int f[N][N];

void Floyd(int n)
{
    int i, j, k;
    
    for(k = 0;k < n;k ++)
        for(i = 0;i < n;i ++)
            for(j = 0;j < n;j ++)
                if(i != j && j != k && i != k)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    
    return;
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
    
    Floyd(n);
    cout << f[0][n - 1] << endl;
    
    return 0;
}
