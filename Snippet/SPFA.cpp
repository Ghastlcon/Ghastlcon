#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#define N 120
#define M 10020
#define INFINITE 999999999
using namespace std;

vector<pair<int, int> > e[N];

int SPFA(int n, int s, int t)
{
    int d[N], c[N];
    bool k[N] = { false };
    deque<int> q;
    int i, u;
    
    for(i = 0;i < n;i ++)
    {
        d[i] = INFINITE;
        c[i] = 0;
    }
    q.push_back(s);
    
    for(d[s] = 0, c[s] = 1, k[s] = true;!q.empty();q.pop_front())
    {
        /*for(i = u = 0;i < (signed)q.size();i ++)//LLL
            u += d[q.at(i)];
        for(u /= q.size();d[q.front()] > u;)
        {
            q.push_back(q.front());
            q.pop_front();
        }*/
        
        u = q.front();
        k[u] = false;
        for(i = 0;i < (signed)e[u].size();i ++)
            if(d[e[u].at(i).first] > d[u] + e[u].at(i).second)
            {
                d[e[u].at(i).first] = d[u] + e[u].at(i).second;
                if(!k[e[u].at(i).first])
                {
                    if(++ c[e[u].at(i).first] > n)
                        return -1;

                    if(!q.empty() && d[e[u].at(i).first] < d[q.front()])//SLF
                        q.push_front(e[u].at(i).first);
                    else
                        q.push_back (e[u].at(i).first);
                    k[e[u].at(i).first] = true;
                }
            }
    }

    return d[t];
}

int main()
{
    int n, m;
    int i, u;
    EDGE t;
    
    cin >> n >> m;
    for(i = 0;i < m;i ++)
    {
        cin >> u >> t.v >> t.w;
        e[u].push_back(t);
    }

    cout << SPFA(n, 0, n - 1) << endl;
    
    return 0;
}
