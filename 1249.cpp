#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

string al[26] = {"2", "22", "222",
				 "3", "33", "333",
				 "4", "44", "444",
				 "5", "55", "555",
				 "6", "66", "666",
				 "7", "77", "777", "7777",
				 "8", "88", "888",
				 "9", "99", "999", "9999",
				};
int cg[26];

int main()
{
	int x;
	string tx, pr;
	int i, j, k, l;
	
	freopen("1249.in" , "r", stdin);
	freopen("1249.out", "w", stdout);
	
	for(i = 1;i <= 9;i ++)
	{
		cin >> x;
		for(j = 0;j < 26;j ++)
			if(al[j][0] == (x + 48) && !cg[j])
			{
				for(k = 0;k < al[j].size();k ++)
					al[j][k] = i + 48;
				cg[j] = 1;
			}
	}
	cin >> tx;
	
	for(i = 0, pr = "0", l = tx.size();i < l;i ++)
	{
		tx[i] = tolower(tx[i]);
		if(pr[0] == al[tx[i] - 97][0])
			cout << '#';
		
		cout << al[tx[i] - 97];
		pr = al[tx[i] - 97];
	}
	
	return 0;
}
