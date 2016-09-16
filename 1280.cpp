#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1020
using namespace std;

int w[N];
int n, m;

int main()
{
	int i, j, k, l;
	int ans;
	
	freopen("1280.in" , "r", stdin);
	freopen("1280.out", "w", stdout);
	
	cin >> n >> m;
	for(i = 0;i < n;i ++)
		cin >> w[i];
	
	for(i = ans = 0;i < n;i ++)
	{
		for(j = i, k = l = 0;j < n;j ++)
		{
			if(k + w[j] > m)
				continue;
			k += w[j];
			l ++;
		}
		ans = max(ans, l);
	}
	cout << ans << endl;
	
	return 0;
}
