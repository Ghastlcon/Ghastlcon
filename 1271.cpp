#include <iostream>
#include <cstdio>
using namespace std;

int f[30][3];

int main()
{
	int n;
	int i, j, ans;
	
	freopen("1271.in" , "r", stdin);
	freopen("1271.out", "w", stdout);
	
	cin >> n;
	for(f[0][0] = f[0][1] = f[0][2] = i = 1;i <= n;i ++)
		for(j = i - 1;j >= i - 3 && j > -1;j --)
		{
			f[i][0] += f[j][1] + f[j][2];
			f[i][1] += f[j][0] + f[j][2];
			f[i][2] += f[j][0] + f[j][1];
		}
	
	cout << (f[n][0] + f[n][1] + f[n][2]) / 2 << endl;
	
	return 0;
}
