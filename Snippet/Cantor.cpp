#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int fac(int x)
{
	int i, s;
	
	for(s = 1, i = 2;i <= x;i ++)
		s *= i;
	
	return s;
}

vector<int> Cantor(int n, int k)
{
    vector<int> u;
    int i, j, t, a, ans;
    bool ok[32] = { false };
    
    for(j = n;j > 1;j --)
	{
        t = fac(j - 1);
		a = (k - 1) / t;
		for(i = 1, ans = 0;i <= n;i ++)
		{
			ans += !ok[i];
			if(ans > a)
				break;
		}
		ok[i] = true;
		u.push_back(i);

		while(k > t)
			k -= t;
	}
	
	for(i = 1;i <= n;i ++)
		if(!ok[i])
		{
			u.push_back(i);
			break;
		}
    
    return u;
}

int UnCantor(int n, vector<int> u)
{
    int i, j, k, ans;
    
    for(i = k = 0;i < n - 1;i ++)
    {
        for(j = i + 1, ans = 0;j < n;j ++)
			if(u.at(j) > u.at(i))
				ans ++;
		k += fac(n - i - 1) * (n - i - ans - 1);
    }
    
    return k + 1;
}

int main()
{
    vector<int> u;
    
    u.push_back(3);
    u.push_back(1);
    u.push_back(4);
    u.push_back(2);
    cout << UnCantor(4, u);
    
    return 0;
}
