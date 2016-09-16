#include <iostream>
#include <cstdio>
using namespace std;

int f[50][2];

int main()
{
	int r, n;
	int i, j;
	
	freopen("1266.in" , "r", stdin);
	freopen("1266.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> n;
		for(i = 2, f[0][0] = f[1][1] = 1;i <= n;i ++)
		{
			f[i][0] = f[i - 1][0] + f[i - 2][0];
			f[i][1] = f[i - 1][1] + f[i - 2][1];
		}
		cout << f[n][0] << ' ' << f[n][1] << endl;
	}
	
	return 0;
}
