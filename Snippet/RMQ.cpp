#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define N 120
#define M 30
using namespace std;

int f[N][M];

void InitRMQ(vector<int> &u)
{
    int i, j, l;
    
    for(i = 0, l = u.size();i < l;i ++)
        f[i][0] = u.at(i);
    for(j = 1;j < M;j ++)
        for(i = 0;i < l;i ++)
            if(i + (1 << j) - 1 < l)
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

    for(i = 1;i <= n;i ++)
        g[i] = g[i - 1] + ((1 << (g[i - 1] + 1)) < i);
    
    return;
}

int MinRMQ(int l, int r)
{
    return min(f[l][g[r - l + 1]], f[r - (1 << g[r - l + 1]) + 1][g[r - l + 1]]);
}

int main()
{
    vector<int> u;
    int n;
    int i, x;
    
    cin >> n;
    for(i = 0;i < n;i ++)
    {
        cin >> x;
        u.push_back(x);
    }
    InitRMQ(u);
    
    while(1)
    {
        cin >> i >> x;
        cout << MinRMQ(i, x) << endl;
    }
    
    return 0;
}
