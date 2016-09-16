#include <iostream>
#include <cstdio>
using namespace std;

long long a[20];

long long fac(long long x)
{
	long long i, s;
	
	for(s = 1, i = 2;i <= x;i ++)
		s *= i;
	
	return s;
}

int main()
{
	long long n;
	long long i, k, sum, ans;
	
	freopen("1256.in" , "r", stdin);
	freopen("1256.out", "w", stdout);
	
	cin >> n;
	for(i = ans = 0;i < n;i ++)
		cin >> a[i];
	
	for(i = 0;i < n - 1;i ++)
	{
		for(k = i + 1, sum = 0;k < n;k ++)
			if(a[k] > a[i])
				sum ++;
		ans += fac(n - i - 1) * (n - i - sum - 1);
	}
	cout << ans + 1 << endl;
	
	return 0;
}
