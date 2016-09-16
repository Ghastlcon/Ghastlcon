#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct
{
	int l;
	int r;
}CHUNK;

CHUNK c[10020];

bool cmp(CHUNK a, CHUNK b)
{
	if(a.r != b.r)
		return a.r < b.r;
	return a.l > b.l;
}

int main()
{
	int n;
	int i, p, ans;
	
	freopen("1263.in" , "r", stdin);
	freopen("1263.out", "w", stdout);
	
	cin >> n;
	for(i = 0;i < n;i ++)
	{
		cin >> c[i].l >> c[i].r;
		c[i].r --;
	}
	sort(c, c + n, cmp);
	
	for(i = ans = p = 0;i < n;i ++)
		if(c[i].l > p)
		{
			ans ++;
			p = c[i].r;
		}
	cout << ans << endl;
	
	return 0;
}
