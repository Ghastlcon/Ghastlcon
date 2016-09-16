#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 50
using namespace std;

int fr[N], fg[N], fb[N];

int main()
{
	int r, n;
	int i, a, b, c;
	
	freopen("1277.in" , "r", stdin);
	freopen("1277.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> n;
		memset(fr, 0, sizeof(fr));
		memset(fg, 0, sizeof(fg));
		memset(fb, 0, sizeof(fb));
		
		for(i = 1;i <= n;i ++)
		{
			cin >> a >> b >> c;
			fr[i] = min(fg[i - 1], fb[i - 1]) + a;
			fg[i] = min(fr[i - 1], fb[i - 1]) + b;
			fb[i] = min(fr[i - 1], fg[i - 1]) + c;
		}
		cout << min(min(fr[n], fg[n]), fb[n]) << endl;
	}
	
	return 0;
}
