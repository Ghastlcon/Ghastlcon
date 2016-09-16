#include <iostream>
#include <cstdio>
using namespace std;

void getb(int x)
{
	if(!x)
		return;
	getb(x / 2);
	cout << x % 2;
	
	return;
}

int main()
{
	int n;
	
    freopen("1241.in" , "r", stdin);
    freopen("1241.out", "w", stdout);

	cin >> n;
	if(n)
		getb(n);
	else
		cout << 0;
	cout << endl;
	
	return 0;
}
