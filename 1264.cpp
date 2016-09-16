#include <iostream>
#include <cstdio>
using namespace std;

int o[10];
string f[70], s[10] = {"0",
					   "1",
					   "2",
					   "3",
					   "4",
					   "5",
					   "6",
					   "7",
					   "8",
					   "9",
					  };

int cmp(string a, string b)
{
	int i, l1, l2;
	int tle, mle;
	
	l1 = tle = a.size();
	l2 = mle = b.size();
	for(i = 0;i < tle && a[i] == '0';i ++, l1 --)
		;
	for(i = 0;i < mle && b[i] == '0';i ++, l2 --)
		;
	
	if(l1 != l2)
		return l1 > l2;
	
	for(i = 0;i < l1;i ++)
		if(a[i] != b[i])
			return a[i] > b[i];
	return 0;
}

int main()
{
	int r, n, m;
	int i, j, z, tm;
	string ans;
	
	freopen("1264.in" , "r", stdin);
	freopen("1264.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> n >> m;
		for(i = 0;i < n;i ++)
			cin >> o[i];
		
		for(z = 0, ans = "";o[0] * z <= m;z ++)
		{
			for(i = 0;i <= m;i ++)
				f[i] = "";
			
			tm = m - o[0] * z;
			for(i = 1;i <= tm;i ++)
				for(j = 1, f[i] = "";j < n;j ++)
					if(i - o[j] > -1 && !cmp(f[i], s[j] + f[i - o[j]]))
						f[i] = s[j] + f[i - o[j]];
			for(i = 0;i < z;i ++)
				f[tm] += s[0];
			
			if(!cmp(ans, f[tm]))
				ans = f[tm];
		}
		
		for(i = 0, z = ans.size();i < z && ans[i] == '0';i ++)
			;
		for(j = i;j < z;j ++)
			cout << ans[j];
		if(i == z)
			cout << '0';
		cout << endl;
	}
	
	return 0;
}
