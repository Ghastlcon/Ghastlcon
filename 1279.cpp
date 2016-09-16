#include <iostream>
#include <cstdio>
#include <cstring>
#define N 70
#define M 1020
using namespace std;

int f[N][M];

int main()
{
	int r, n, c, bl, ml;
	int i, j;
	
	freopen("1279.in" , "r", stdin);
	freopen("1279.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> n >> bl >> ml;
		memset(f, 0, sizeof(f));
		
		for(i = f[0][bl] = 1;i <= n;i ++)
		{
			cin >> c;
			for(j = 0;j <= ml;j ++)
				if(j - c > -1 && f[i - 1][j - c] || j + c <= ml && f[i - 1][j + c])
					f[i][j] = 1;
		}
		
		for(i = ml;i > -1;i --)
			if(f[n][i])
			{
				cout << i;
				goto nxt;
			}
		cout << -1;
		nxt:;
		cout << endl;
	}
	
	return 0;
}
