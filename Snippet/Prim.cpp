//Warning : Start From 1.
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#define N 120
#define INFINITE 999999999
using namespace std;

int k;
pair<int, int> f[N * 4];
vector<pair<int, int> > e[N];
int p[N][N];

void InitWinner(int n)
{
    int i;
    
    k = pow(2, ceil((log(n) / log(2))));
    for(i = 0;i < n;i ++)
    {
        f[i + k].first  = p[1][i + 1];
        f[i + k].second = i + 1;
    }
    for(i = n + k;i < 2 * k;i ++)
        f[i].first = INFINITE;
    
    for(i = k - 1;i;i --)
    {
        f[i].first  = min(f[2 * i].first, f[2 * i + 1].first);
        f[i].second = (f[2 * i].first < f[2 * i + 1].first ? f[2 * i].second : f[2 * i + 1].second);
    }
    
    return;
}

void UpdateWinner(int x, int y)
{
    for(f[x = x + k - 1].first = y;x /= 2;)
    {
        f[x].first  = min(f[x * 2].first, f[x * 2 + 1].first);
        f[x].second = (f[2 * x].first < f[2 * x + 1].first ? f[2 * x].second : f[2 * x + 1].second);
    }
    
    return;
}

int Prim(int n)
{
    bool u[N] = { false };
    int i, j, t, x, ans;
    
    for(i = ans = 0, u[1] = true, UpdateWinner(1, INFINITE);i < n - 1;i ++)
    {
        ans += f[1].first;
        u[f[1].second] = true;
        x = f[1].second;
        UpdateWinner(f[1].second, INFINITE);
        
        for(j = 0;j < (signed)e[x].size();j ++)
        {
            t = e[x].at(j).first;
            if(!u[t] && f[k + t - 1].first > e[x].at(j).second)
                UpdateWinner(t, e[x].at(j).second);
        }
    }
    
    return ans;
}

int main()
{
    int n;
    int i, j;
    
    
    cin >> n;
    for(i = 1;i <= n;i ++)
        for(j = 1;j <= n;j ++)
        {
            cin >> p[i][j];
            if(i < j)
            {
                e[i].push_back(make_pair(j, p[i][j]));
                e[j].push_back(make_pair(i, p[i][j]));
            }
        }
    
    InitWinner(n);
    cout << Prim(n) << endl;
    
    return 0;
}

