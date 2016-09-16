#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#define N 5020
#define INFINITE 999999999
using namespace std;

int a[N], b[N];
int f[N];
map<int, int> u;

int main()
{
	int n, k;
	int i, j, ans, d;
	
	freopen("1252.in" , "r", stdin);
	freopen("1252.out", "w", stdout);
	
	cin >> n >> k;
	for(i = 0;i < n;i ++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	
	for(i = 0, d = n / k;i < d;i ++)
		for(j = 0;j < k;j ++)
			u[a[i * k + j]] = i + 1;
	for(i = 0;i < n;i ++)
		a[i] = u[b[i]];
	
	for(i = 0, ans = -INFINITE;i < n;i ++)
	{
		for(f[i] = 1, j = i - 1;j > -1;j --)
			if(a[j] <= a[i])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << n - ans << endl;
	
	return 0;
}
