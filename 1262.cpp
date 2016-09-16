#include <iostream>
#include <cstdio>
#define N 120
#define M 50020
#define INFINITE 999999999
using namespace std;

int f[M], a[N];

int main()
{
	int n, m;
	int i, j;
	
	freopen("1262.in" , "r", stdin);
	freopen("1262.out", "w", stdout);
	
	cin >> n;
	for(i = 1;i <= n;i ++)
		cin >> a[i];
	cin >> m;
	
	for(i = 1;i <= m;i ++)
		for(j = 1, f[i] = INFINITE;j <= n;j ++)
			if(i - a[j] > -1)
				f[i] = min(f[i], f[i - a[j]] + 1);
	cout << (f[m] == INFINITE ? -1 : f[m]) << endl;
	
	return 0;
}
