#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 30
#define K 8
#define MOD 1000000007
using namespace std;

int f[N + 1][N + 1][1 << (K + 1)][K + 1];

int main()
{
    int n, m, k;
    int i, j, t, p, l;

    freopen("1791.in" , "r", stdin );
    freopen("1791.out", "w", stdout);

    cin >> n >> m >> k;
    for(i = 0;i <= k;i ++)
        f[n][0][0][i] = 1;

    for(i = n - 1;i > -1;i --)
        for(j = 0;j <= m;j ++)
            for(t = 0;t < (1 << (k + 1));t ++)
                for(p = 1;p <= k;p ++)
                    for(l = p, f[i][j][t][p] += (!(t & 1)) * f[i + 1][j][t >> 1][1];l <= k;l ++)
                        f[i][j][t][p] = (f[i][j][t][p] + (i + l <  n && j) * f[i][j - 1][t ^ 1 ^ (1 << l)][l]) % MOD;
    cout << f[0][m][0][1] << endl;

    return 0;
}
