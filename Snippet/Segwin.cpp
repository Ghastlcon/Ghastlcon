#include <iostream>
#include <algorithm>
#include <string>
#define N 120
using namespace std;

int n;
int f[N * 2];

void BuildSegwin(void)
{
    int i;

    for(i = n - 1;i > 0;i --)
        f[i] = f[i << 1] + f[i << 1 | 1];

    return;
}

int SumSegwin(int s, int t)
{
    int o;

    for(s += n, t += n + 1, o = 0;s < t;s >>= 1, t >>= 1)
    {
        o += (s & 1 ? f[s ++] : 0);
        o += (t & 1 ? f[-- t] : 0);
    }

    return o;
}

void AddSegwin(int p, int v)
{
    for(f[p += n] += v;p >>= 1;)
        f[p] = f[p << 1] + f[p << 1 | 1];

    return;
}

int main()
{
    int u, v;
    string s;
    int i;

    cin >> n;
    for(i = 0;i < n;i ++)
        cin >> f[i + n];
    BuildSegwin();

    while(true)
    {
        cin >> s >> u >> v;

        if(s == "Add")
            AddSegwin(u, v);
        else if(s == "Query")
        {
            if(u > v)
                swap(u, v);
            cout << SumSegwin(u, v) << endl;
        }
    }

    return 0;
}
