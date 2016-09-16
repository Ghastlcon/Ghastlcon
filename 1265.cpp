#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#define N 20
using namespace std;

int prime[11] = {1 ,
				 4 ,
				 6 ,
				 8 ,
				 9 ,
				 10,
				 12,
				 14,
				 15,
				 16,
				 18,
			   };
double f[N][N], g[N][N];

int main()
{
	int r;
	double a, b;
	int i, j;
	double a1, a2;
	char out[N];
	
	freopen("1265.in" , "r", stdin);
	freopen("1265.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> a >> b;
		a /= 100;
		b /= 100;
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		
		
		f[1][1] =     a;
		f[1][0] = 1 - a;
		g[1][1] =     b;
		g[1][0] = 1 - b;
		for(i = 2;i <= 18;i ++)
		{
			f[i][0] = (1 - a) * f[i - 1][0];
			g[i][0] = (1 - b) * g[i - 1][0];
		}
		
		for(i = 2;i <= 18;i ++)
			for(j = 1;j <= 18;j ++)
			{
				f[i][j] = (1 - a) * f[i - 1][j] + a * f[i - 1][j - 1];
				g[i][j] = (1 - b) * g[i - 1][j] + b * g[i - 1][j - 1];
			}
		
		for(i = a1 = a2 = 0;i < 12;i ++)
		{
			a1 += f[18][prime[i]];
			a2 += g[18][prime[i]];
		}

		cout.setf(ios::fixed);
		cout << setprecision(16) << 1 - a1 * a2 << endl;
	}
	
	return 0;
}
