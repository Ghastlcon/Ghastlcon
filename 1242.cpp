#include <iostream>
#include <cstdio>
using namespace std;

int n, a[50], u[50];

void dfs(int s)
{
	int i;
	
	if(s >= n)
	{
		for(i = 0;i < n;i ++)
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
	freopen("1242.in" , "r", stdin);
	freopen("1242.out", "w", stdout);
	
	cin >> n;
	dfs(0);
	
	return 0;
}
