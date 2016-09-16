#include <iostream>
#include <cstdio>
using namespace std;

int n;
int s[150], m[150];

void gc(int xs, int xt, int ys, int yt)
{
	int i;
	
	if(ys >= yt)
	{
		if(yt == ys && ys > -1 && ys < n)
			cout << m[ys] << ' ';
		return;
	}
	
	for(i = ys;i <= yt;i ++)
		if(m[i] == s[xs])
        {
			gc(xs + 1               , xs + 1 + (i - 1 - ys), ys   , i - 1);
			gc(xs + 2 + (i - 1 - ys), xt                   , i + 1, yt   );
			
			cout << m[i] << ' ';
		}
	
	return;
}

int main()
{
	int i;
	
	freopen("1244.in" , "r", stdin);
	freopen("1244.out", "w", stdout);
	
	cin >> n;
	for(i = 0;i < n;i ++)
		cin >> s[i];
	for(i = 0;i < n;i ++)
		cin >> m[i];
	gc(0, n - 1, 0, n - 1);
	
	return 0;
}
