#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#define N 10020
using namespace std;

vector<int> e[N];
stack<int> s;
int p, d[N], l[N], b[N];
bool u[N];

void Tarjan(int x)
{
    static int t = 0;
    int i;

    d[x] = l[x] = ++ t;
    u[x] = true;
    s.push(x);

    for(i = 0;i < (signed)e[x].size();i ++)
    {
        if(!d[e[x].at(i)])
        {
            Tarjan(e[x].at(i));
            l[x] = min(l[x], l[e[x].at(i)]);
        }
        else if(u[e[x].at(i)])
            l[x] = min(l[x], d[e[x].at(i)]);
    }

    if(d[x] == l[x])
    {
        do
        {
            i = s.top();
            s.pop();
            u[i] = false;
            b[i] = p;
        }while(i != x);
        p ++;
    }

    return;
}

int main()
{
    int n, m;
    int i, j;

    cin >> n >> m;
    while(m --)
    {
        cin >> i >> j;
        e[i].push_back(j);
    }

    for(i = p = 0;i < n;i ++)
        if(!d[i])
            Tarjan(i);

    for(i = 0;i < n;i ++)
        cout << b[i] << ' ';
    cout << endl;
    
    return 0;
}
