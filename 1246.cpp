#include <iostream>
#include <cstdio>
using namespace std;

int n, a[1000020], b[1000020];

void merge_sort(int l, int r)
{
	int i, j;
	int p, q, m;
	
	if(l >= r)
		return;
	m = (l + r) / 2;
	merge_sort(l    , m);
	merge_sort(m + 1, r);
	
	for(i = p = l, q = m + 1;p <= m || q <= r;i ++)
		if(q > r || p <= m && a[p] <= a[q])
			b[i] = a[p ++];
		else
			b[i] = a[q ++];
	for(i = l;i <= r;i ++)
		a[i] = b[i];

	return;
}

int main()
{
	int i;
	
	freopen("1246.in" , "r", stdin);
	freopen("1246.out", "w", stdout);
	
	cin >> n;
	for(i = 0;i < n;i ++)
		cin >> a[i];
	
	merge_sort(0, n - 1);
	for(i = 0;i < n;i ++)
		cout << a[i] << ' ';
	cout << endl;
	
	return 0;
}
