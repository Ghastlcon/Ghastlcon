#include <iostream>
#include <cstdio>
#include <algorithm>
#define INFINITE 999999999
using namespace std;

int f[20], ans;

void gc(int n, int s)
{
	int i;
	
	if(n >= 20)
	{
		for(i = 0;i < 20;i ++)
			if(f[i])
				return;
		ans = min(ans, s);
		return;
	}
	else if(!n)
	{
		f[n    ] = !f[n    ];
		f[n + 1] = !f[n + 1];
		gc(n + 1, s + 1);
		f[n    ] = !f[n    ];
		f[n + 1] = !f[n + 1];
	}
	else if(n == 19)
	{
		f[n    ] = !f[n    ];
		f[n - 1] = !f[n - 1];
		gc(n + 1, s + 1);
		f[n    ] = !f[n    ];
		f[n - 1] = !f[n - 1];
	}
	else
	{
		f[n - 1] = !f[n - 1];
		f[n    ] = !f[n    ];
		f[n + 1] = !f[n + 1];
		gc(n + 1, s + 1);
		f[n - 1] = !f[n - 1];
		f[n    ] = !f[n    ];
		f[n + 1] = !f[n + 1];
	}
	gc(n + 1, s);
	
	return;
}

int main()
{
	int i, fg;
	
	freopen("1257.in" , "r", stdin);
	freopen("1257.out", "w", stdout);
	
	for(i = fg = 0;i < 20;i ++)
	{
		cin >> f[i];
		if(f[i])
			fg = 1;
	}
	ans = (fg ? INFINITE : 0);
	
	if(fg)
		gc(0, 0);
	cout << (ans == INFINITE ? -1 : ans) << endl;
	
	return 0;
}
