#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 370
#define M 50
using namespace std;

int a[N];
int c[4], f[M][M][M][M];

int main()
{
    int n, m;
    int i, j, k, l;
    
    freopen("1809.in" , "r", stdin );
    freopen("1809.out", "w", stdout);
    
    cin >> n >> m;
    for(i = 0;i < n;i ++)
        cin >> a[i];
    while(m --)
    {
        cin >> i;
        c[-- i] ++;
    }

    for(i = 0;i <= c[0];i ++)
        for(j = 0;j <= c[1];j ++)
            for(k = 0;k <= c[2];k ++)
                for(l = 0;l <= c[3];l ++)
                {
                    f[i][j][k][l] = a[i + j * 2 + k * 3 + l * 4];
                    f[i][j][k][l] = max(f[i][j][k][l], (i ? f[i - 1][j][k][l] + a[i + j * 2 + k * 3 + l * 4] : 0));
                    f[i][j][k][l] = max(f[i][j][k][l], (j ? f[i][j - 1][k][l] + a[i + j * 2 + k * 3 + l * 4] : 0));
                    f[i][j][k][l] = max(f[i][j][k][l], (k ? f[i][j][k - 1][l] + a[i + j * 2 + k * 3 + l * 4] : 0));
                    f[i][j][k][l] = max(f[i][j][k][l], (l ? f[i][j][k][l - 1] + a[i + j * 2 + k * 3 + l * 4] : 0));
                }
    cout << f[c[0]][c[1]][c[2]][c[3]] << endl;
    
    return 0;
}
