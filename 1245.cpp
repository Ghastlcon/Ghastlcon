#include <iostream>
#include <cstdio>
using namespace std;

int n, m;

void pts(int x)
{
	if(x == n + 1)
		return;
	
	if(x)
		cout << x << ' ';
	if(x < 1)
		m = 1;
	pts(x - (m ? -1 : 1));
	
	return;
}

int main()
{
	freopen("1245.in" , "r", stdin);
	freopen("1245.out", "w", stdout);
	
	cin >> n;
	pts(n);
	cout << endl;
	
	return 0;
}
