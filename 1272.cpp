#include <iostream>
#include <cstdio>
using namespace std;

int m, n;
int c[20][20], f[20][20];

void init(void)
{
	int i, j;
	
	for(i = 0;i < 11;i ++)
		for(j = 0;j <= i;j ++)
			c[i][j] = (!j || j == i ? 1 : c[i - 1][j] + c[i - 1][j - 1]);
	
	return;		
}

int fac(int x)
{
	int i, s;
	
	for(i = 2, s = 1;i <= x;i ++)
		s *= i;
	
	return s;
}

int main()
{
	int i, j, k;
	
	freopen("1272.in" , "r", stdin);
	freopen("1272.out", "w", stdout);
	
	init();
	cin >> m >> n;
	
	for(i = f[0][0] = 1;i <= n;i ++)
		for(j = m;j > -1;j --)
		{
			for(k = 1;k <= j;k ++)
				f[i][j] += f[i - 1][j - k] * c[j][k];
		}
	cout << f[n][m] / fac(n) << endl;
	
	return 0;
}
