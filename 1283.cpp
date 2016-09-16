#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long n, a, b;
long long x[20];
vector<long long> v;

long long count(long long u)
{
	long long ta = (b / u);
	long long tb = (a - 1ll) / u;
	return ta - tb;
}

int main()
{
	long long i, j, k, l;
	long long bs, ans;
	
	freopen("1283.in" , "r", stdin);
	freopen("1283.out", "w", stdout);
	
	cin >> n >> a >> b;
	for(i = ans = 0;i < n;i ++)
		cin >> x[i];
	
	if((b - a) * n <= 10000000)
	{
		for(;a <= b;a ++)
			for(i = 0;i < n;i ++)
				if(!(a % x[i]))
				{
					ans ++;
					break;
				}
	}
	else
	{
		for(i = 1;i < (1 << n);i ++)
		{
			for(j = bs = 0, v.clear();j < n;j ++)
				if(i & (1 << j))
				{
					bs ++;
					v.push_back(x[j]);
				}
			
			l = v.size();
			for(j = 0, k = 1;j < l;j ++)
			{
				k *= v[j];
				if(k > b)
					goto nxt;
			}
	
			ans += (bs % 2 ? 1 : -1) * count(k);
			nxt:;
		}
	}
	cout << ans <<endl;
	
	return 0;
}
