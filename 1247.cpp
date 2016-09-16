#include <iostream>
#include <cstdio>
using namespace std;

long long n, a[100020], b[100020];
long long ans;

void merge_sort(long long l, long long r)
{
	long long i, j;
	long long p, q, m;
	
	if(l >= r)
		return;
	m = (l + r) / 2;
	merge_sort(l    , m);
	merge_sort(m + 1, r);
	
	for(i = p = l, q = m + 1;p <= m || q <= r;i ++)
		if(q > r || p <= m && a[p] <= a[q])
			b[i] = a[p ++];
		else
		{
			b[i] = a[q ++];
			ans += (m >= p ? m - p + 1 : 0);
		}
	for(i = l;i <= r;i ++)
		a[i] = b[i];

	return;
}

int main()
{
	long long i;
	
	freopen("1247.in" , "r", stdin);
	freopen("1247.out", "w", stdout);
	
	cin >> n;
	for(i = 0;i < n;i ++)
		cin >> a[i];
	
	merge_sort(0, n - 1);
	cout << ans << endl;
	
	return 0;
}
