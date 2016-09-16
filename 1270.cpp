#include <iostream>
#include <cstdio>
using namespace std;

int f[50][2];

int main()
{
	int n;
	int i;
	
	freopen("1270.in" , "r", stdin);
	freopen("1270.out", "w", stdout);
	
	cin >> n;
	for(i = 2, f[0][0] = f[1][0] = f[0][1] = f[1][1] = 1;i <= n;i ++)
	{
		f[i][0] += f[i - 1][1] + f[i - 2][1];
		f[i][1] += f[i - 1][0] + f[i - 2][0];
	}
	cout << f[n][0] + f[n][1] << endl;
	
	return 0;
}
