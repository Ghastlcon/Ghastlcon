#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1020
#define INFINITE 999999999
using namespace std;

const int dirx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int diry[8] = {1, -1, 0, 0, -1, 1, 1, -1};

int mp[N][N];

int main()
{
	int n, l, r, h;
	int ml, mr, mh;
	int i, j, k, ans;
	
	freopen("1253.in" , "r", stdin);
	freopen("1253.out", "w", stdout);
	
	cin >> n;
	for(i = 0, ml = INFINITE, mr = mh = -1;i < n;i ++)
	{
		cin >> l >> r >> h;
		r --;
		
		ml = min(ml, l);
		mr = max(mr, r);
		mh = max(mh, h);
		
		for(j = 1;j <= h;j ++)
			for(k = l;k <= r;k ++)
				mp[j][k] = 1;
	}
	for(i = ml;i <= mr;i ++)
		mp[0][i] = 2;

	for(i = 1, ans = 0;i <= mh;i ++)
		for(j = ml;j <= mr;j ++)
			if(mp[i][j] == 1)
				for(k = 0;k < 4;k ++)
					if(!mp[i + dirx[k]][j + diry[k]])
						ans ++;
	cout << ans << endl;
	
	for(i = mh;i > 0;i --)
	{
		for(j = ml;j <= mr;j ++)
		{
			if(!mp[i][j])
				cout << '.';
			else if(mp[i][j] == 1)
			{
				for(k = 0;k < 8;k ++)
					if(!mp[i + dirx[k]][j + diry[k]])
					{
						cout << '#';
						goto nxt;
					}
				cout << '.';
			}
			nxt:;
		}
		cout << endl;
	}
	for(i = ml;i <= mr;i ++)
		cout << '*';
	cout << endl;
	
	return 0;
}
