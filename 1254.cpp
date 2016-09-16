#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(char a, char b)
{
	return a > b;
}

int main()
{
	string n;
	int i, l, sum, o;
	
	freopen("1254.in" , "r", stdin);
	freopen("1254.out", "w", stdout);
	
	cin >> n;
	for(i = o = sum = 0, l = n.size();i < l;i ++)
	{
		sum += n[i] - 48;
		o += n[i] == '0';
	}
	
	if(sum % 3 || !o)
		cout << -1;
	else
	{
		sort(n.begin(), n.end(), cmp);
		for(i = 0;i < l;i ++)
			if(n[i] != '0')
				cout << n[i];
		while(o --)
			cout << '0';
	}
	cout << endl;
	
	return 0;
}
