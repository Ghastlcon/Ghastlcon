#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define N 120
using namespace std;

int n;
int f[N];

int Lowbit(int x)
{
    return x & -x;
}

void BuildFenwick(vector<int> &x)
{
    int i;
    int g[N];

    for(i = g[0] = 0, n = x.size();i < n;i ++)
        g[i + 1] = g[i] + x.at(i);
    for(i = 1;i <= n;i ++)
        f[i] = g[i] - g[i - Lowbit(i)];

    return;
}

void AddFenwick(int x, int d)
{
    for(;x <= n;f[x] += d, x += Lowbit(x))
        ;

    return;
}

int SumFenwick(int x)
{
    int r;

    for(r = 0;x;r += f[x], x -= Lowbit(x))
        ;

    return r;
}

int main()
{
    vector<int> a;
    int n, x;
    int i;
    string s;

    cin >> n;
    for(i = 0;i < n;i ++)
    {
        cin >> x;
        a.push_back(x);
    }
    BuildFenwick(a);

    while(true)
    {
        cin >> s >> i;
        if(s == "Modify")
        {
            cin >> x;
            AddFenwick(i, x);
        }
        else if(s == "Query")
            cout << SumFenwick(i) << endl;
    }

    return 0;
}
