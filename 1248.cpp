#include <iostream>
#include <cstdio>
using namespace std;

long long n, k;
int ok[20];

long long fac(int x)
{
	long long i, s;
	
	for(s = 1, i = 2;i <= x;i ++)
		s *= i;
	
	return s;
}

int main()
{
	long long t, a, b;
	int i, sum, tn;
	
	freopen("1248.in" , "r", stdin);
	freopen("1248.out", "w", stdout);
	
	cin >> n >> k;
	for(tn = n;n > 1;)
	{
		t = fac(n - 1);
		a = (k - 1) / t;
		for(i = 1, sum = 0;i <= tn;i ++)
		{
			sum += !ok[i];
			if(sum > a)
				break;
		}
		ok[i] = 1;
		cout << i << ' ';
		//k %= t;
		while(k > t)
			k -= t;
		n --;
	}
	
	for(i = 1;i <= tn;i ++)
		if(!ok[i])
		{
			cout << i << endl;
			break;
		}

	return 0;
}
