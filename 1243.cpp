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

void dfs1(int x)
{
	if(s[x][0])
		dfs1(s[x][0]);
	cout << x << ' ';
	if(s[x][1])
		dfs1(s[x][1]);
	
	return;
}

void dfs2(int x)
{
	if(s[x][0])
		dfs2(s[x][0]);
	if(s[x][1])
		dfs2(s[x][1]);
	cout << x << ' ';
	
	return;
}

int main()
{
	int n;
	int i;
	
	freopen("1243.in" , "r", stdin);
	freopen("1243.out", "w", stdout);
	
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
			dfs1(i);
			cout << endl;
			dfs2(i);
			break;
		}
	
	return 0;
}
