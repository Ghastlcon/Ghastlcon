#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define N 120
#define INFINITE 999999999
using namespace std;

int k;
int f[N * 4];

void InitWinner(int n)
{
    int i, k;

    k = pow(2, ceil((log(n) / log(2))));
    for(i = 0;i < n;i ++)
        cin >> f[i + k];
    for(i = n + k;i < 2 * k;i ++)
        f[i] = -INFINITE;
    for(i = k - 1;i;i --)
        f[i] = max(f[2 * i], f[2 * i + 1]);

    return;
}

void UpdateWinner(int p, int v)
{
    for(f[p += k] = v;p /= 2;)
        f[p] = max(f[p * 2], f[p * 2 + 1]);

    return;
}

int main()
{
    int n, m, x, y;
    string s;

    cin >> n >> m;
    InitWinner(n);
    while(m --)
    {
        cin >> s;
        if(s == "Modify")
        {
            cin >> x >> y;
            UpdateWinner(x, y);
        }
        else if(s == "Query")
            cout << f[1] << endl;
    }

    return 0;
}
