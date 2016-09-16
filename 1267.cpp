#include <iostream>
#include <cstdio>
#define INFINITE 999999999
using namespace std;

long long f[70];

long long cg(string t)
{
	long long i, j, ans;
	
	for(i = t.size() - 1, j = ans = 0;i > -1;i --, j ++)
		ans += (1ll << j) * (t[i] - 48);
	
	return ans;
}

long long ok(long long t)
{
	if(t < 1)
		return 0;
	
	while(t > 1)
	{
		if(t % 5)
			return 0;
		t /= 5;
	}
	
	return 1;
}

int main()
{
	long long r, l;
	long long i, j;
	string b;
	
	freopen("1267.in" , "r", stdin);
	freopen("1267.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> l >> b;
		
		for(i = 0;i < l;i ++)
			for(j = i, f[i] = INFINITE;j > -1;j --)
				if(b[j] == '1' && ok(cg(b.substr(j, i - j + 1))))
					f[i] = min(f[i], (j ? f[j - 1] : 0) + 1);
		cout << (f[l - 1] == INFINITE ? -1 : f[l - 1]) << endl;
	}
	
	return 0;
}
