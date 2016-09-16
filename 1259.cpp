#include <iostream>
#include <cstdio>
using namespace std;

int n, m, a[50], u[50];

void dfs(int s)
{
	int i;
	
	if(s >= m)
	{
		for(i = 0;i < m;i ++)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	for(i = 1;i <= n;i ++)
		if(!u[i])
		{
			a[s] = i;
			u[i] = 1;
			dfs(s + 1);
			u[i] = 0;
		}
	
	return;
}

int main()
{
	freopen("1259.in" , "r", stdin);
	freopen("1259.out", "w", stdout);
	
	cin >> n >> m;
	dfs(0);
	
	return 0;
}
