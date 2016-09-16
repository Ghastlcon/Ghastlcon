#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 120
using namespace std;

typedef struct
{
	int x;
	int y;
}TREE;

int f[N], s[N][2];
TREE t[N];

bool cmp(TREE a, TREE b)
{
	return a.x < b.x;
}

void dfs(int x)
{
	cout << x << ' ';
	if(!s[x][0])
		return;
	dfs(s[x][0]);
	if(s[x][1])
		dfs(s[x][1]);
	
	return;
}

int main()
{
	int n;
	int i;
	
	freopen("1240.in" , "r", stdin);
	freopen("1240.out", "w", stdout);
	
	cin >> n;
	for(i = 0;i < n - 1;i ++)
		cin >> t[i].x >> t[i].y;
	sort(t, t + n - 1, cmp);
	
	for(i = 0;i < n - 1;i ++)
	{
		f[t[i].x] = t[i].y;
		s[t[i].y][(s[t[i].y][0] ? 1 : 0)] = t[i].x;	
	}
	for(i = 1;i <= n;i ++)
		if(!f[i])
		{
			dfs(i);
			break;
		}
	
	return 0;
}
