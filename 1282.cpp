#include <iostream>
#include <cstdio>
#define N 120
using namespace std;

string mp[N];
int f[N][N];

int chunk(int x1, int y1, int x2, int y2)
{
	return f[x2][y2] -
	      (x1 ? f[x1 - 1][y2    ] : 0) -
	      (y1 ? f[x2    ][y1 - 1] : 0) +
	(x1 && y1 ? f[x1 - 1][y1 - 1] : 0);
}

int main()
{
	int n, m, r;
	int i, j, t;
	int ax, ay, ans;
	
	freopen("1282.in" , "r", stdin);
	freopen("1282.out", "w", stdout);
	
	cin >> n >> m >> r;
	for(i = 0;i < n;i ++)
	{
		cin >> mp[i];
		for(j = 0;j < m;j ++)
			f[i][j] = (mp[i][j] == '*') + 
					  (i ? f[i - 1][j    ] : 0) +
					  (j ? f[i    ][j - 1] : 0) -
				 (i && j ? f[i - 1][j - 1] : 0);
	}
	
	for(i = ans = ax = ay = 0;i < n;i ++)
		for(j = 0;j < m;j ++)
			if(i + r - 1 < n && j + r - 1 < m)
			{
				t = chunk(i + 1, j + 1, i + r - 2, j + r - 2);
				if(ans < t)
				{
					ans = t;
					ax  = i;
					ay  = j;
				}
			}
	cout << ans << endl;
	
	mp[ax        ][ay        ] =
	mp[ax        ][ay + r - 1] =
	mp[ax + r - 1][ay        ] =
	mp[ax + r - 1][ay + r - 1] = '+';
	
	for(i = ay + 1;i < ay + r - 1;i ++)
		mp[ax][i] = mp[ax + r - 1][i] = '-';
	for(i = ax + 1;i < ax + r - 1;i ++)
		mp[i][ay] = mp[i][ay + r - 1] = '|';
	for(i = 0;i < n;i ++)
		cout << mp[i] << endl;
	
	return 0;
}
