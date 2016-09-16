#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int f[40][40];

int main()
{
    int m, n;
    int i, j;
    
    freopen("1273.in" , "r", stdin);
	freopen("1273.out", "w", stdout);
    
    cin >> m >> n;
	for(i = 0;i <= max(n, m);i ++)
		f[0][i] = f[i][1] = 1;
	
	for(i = 1;i <= m;i ++)
	    for(j = 1;j <= n;j ++)
	        f[i][j] = (i < j ? 0 : f[i - j][j]) + f[i][j - 1];
    cout << f[m][n] << endl;
    
    return 0;
}
