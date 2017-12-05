#include <iostream>
#include <algorithm>
#define N 120
#define M 10020
#define INFINITE 999999999
using namespace std;

typedef struct
{
    int u;
    int v;
    int w;
}EDGE;

EDGE e[M];

int Bellman(int n, int m, int s, int t)
{
    int d[N];
    int i, j;
    bool k;
    
    for(i = 0;i < n;i ++)
        d[i] = INFINITE;
    for(i = d[s] = 0;i < n - 1;i ++)
    {
        for(j = 0, k = false;j < m;j ++)
            if(d[e[j].v] > d[e[j].u] + e[j].w)
            {
                d[e[j].v] = d[e[j].u] + e[j].w;
                k = true;
            }
        if(!k)
            break;
    }
    
    for(i = 0;i < m;i ++)
        if(d[e[i].v] > d[e[i].u] + e[i].w)
            return -1;

    return d[t];
}

int main()
{
    int n, m;
    int i;
    
    cin >> n >> m;
    for(i = 0;i < m;i ++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    cout << Bellman(n, m, 0, n - 1) << endl;
    
    return 0;
}
