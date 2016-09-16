#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100020
#define INFINITE 999999999
using namespace std;

int n, x;
int v, u[N];
int a[N];

int main()
{
	int i, j, f;
	int l, m, r;
	
	freopen("1255.in" , "r", stdin);
	freopen("1255.out", "w", stdout);
	
	cin >> n;
	for(i = 0;i < n;i ++)
	{
		cin >> x;
		
		if(!u[x])
			a[v ++] = x;
		u[x] ++;
	}
	sort(a, a + v);
	
	if(v == 1)
		cout << "Slavko" << endl << a[0] << ' ' << a[v - 1] << endl;
	else
	{
		for(l = 0, r = v - 1;v > 2;)
		{
			m = min(u[a[l]], u[a[r]]);
			u[a[l    ]] -= m;
			u[a[l + 1]] += m;
			
			if(!u[a[l]])
			{
				l ++;
				v --;
			}
			f = 0;
			if(v < 3)
				break;
			/////////////////////////////////////////////////////////
			u[a[r    ]] -= m;
			u[a[r - 1]] += m;
			
			if(!u[a[r]])
			{
				r --;
				v --;
			}
			f = 1;
		}
		cout << (!f ? "Mirko" :"Slavko" ) << endl << a[l] << ' ' << a[r] << endl;
	}
	
	return 0;
}
