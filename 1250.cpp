#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100020
using namespace std;

int n;
string o[N * 2];

int main()
{
	int i, j;
	
	freopen("1250.in" , "r", stdin);
	freopen("1250.out", "w", stdout);
	
	cin >> n;
	for(i = 0;i < n * 2 - 1;i ++)
		cin >> o[i];
	sort(o, o + n * 2 - 1);
	
	for(i = 0;i < n * 2 - 1;i ++)
		if(!(i % 2) && o[i] != o[i + 1])
		{
			cout << o[i];
			break;
		}
	
	return 0;
}
