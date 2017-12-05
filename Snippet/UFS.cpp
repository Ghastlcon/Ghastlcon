#include <iostream>
#include <algorithm>
#define N 120
using namespace std;

int f[N];

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

void MergeUFS(int x, int y)
{
    int p, q;
    
    p = GetUFS(x);
    q = GetUFS(y);
    if(p != q)
        f[p] = q;
    
    return;
}

int main()
{
    int n, m, x, y;
    int i;
    
    for(i = 0;i < N;i ++)
        f[i] = i;
    cin >> n >> m;
    for(i = 0;i < m;i ++)
    {
        cin >> x >> y;
        MergeUFS(x, y);
    }
    
    for(i = x = 0;i < n;i ++)
        if(f[i] == i)
            x ++;
     cout << x << endl;
    
    return 0;
}
