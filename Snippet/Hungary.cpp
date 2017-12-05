#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 120
using namespace std;

vector<int> e[N];
int o[N];
bool u[N];

bool MatchHungary(int x)
{
    int i, v;

    for(i = 0;i < (signed)e[x].size();i ++)
        if(!u[v = e[x].at(i)])
        {
            u[v] = true;
            if(o[v] == -1 || MatchHungary(o[v]))
            {
                o[v] = x;
                o[x] = v;

                return true;
            }
        }

    return false;
}

int Hungary(int n)
{
    int i, v;

    memset(o, -1, sizeof(o));
    for(i = v = 0;i < n;i ++)
        if(o[v] == -1)
        {
            memset(u, false, sizeof(u));
            v += MatchHungary(v);
        }

    return v;
}

int main()
{
    int n, m, u, v;

    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cout << Hungary(n) << endl;

    return 0;
}
