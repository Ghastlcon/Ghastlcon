#include <iostream>
#include <cstdio>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 80
#define INFINITE 999999999
using namespace std;

int b[3], t[3];
int f[N][N][N];

void update(int &x, int a, int b, int c)
{
	int ta, tb, tc;
	
	ta = MAX(0, a                );
	tb = MAX(0, b                );
	tc = MAX(0, c                );
	x  = MIN(x, f[ta][tb][tc] + 1);
	
	return;
}

int main()
{
	int r, n;
	int i, j, k;
	int ta, tb, tc;
	
	freopen("1278.in" , "r", stdin);
	freopen("1278.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> n;
		for(i = b[0] = b[1] = b[2] = 0;i < n;i ++)
			cin >> b[i];
		
		for(i = 0;i <= b[0];i ++)
			for(j = 0;j <= b[1];j ++)
				for(k = 0;k <= b[2];k ++)
					if(i || j || k)
					{
						f[i][j][k] = INFINITE;
						update(f[i][j][k], i - 1, j - 3, k - 9);
						update(f[i][j][k], i - 1, j - 9, k - 3);
						update(f[i][j][k], i - 3, j - 1, k - 9);
						update(f[i][j][k], i - 3, j - 9, k - 1);
						update(f[i][j][k], i - 9, j - 1, k - 3);
						update(f[i][j][k], i - 9, j - 3, k - 1);
					}
					else
						f[i][j][k] = 0;
		cout << f[b[0]][b[1]][b[2]] << endl;
	}
	
	return 0;
}
