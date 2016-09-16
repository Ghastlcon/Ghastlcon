#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define N 70
#define INFINITE 999999999
using namespace std;

typedef struct
{
	string o;
	string n;
}WORD;

string t;
WORD w[N];
int f[N];
map<string, vector<int> > u;

int main()
{
	int r, n;
	int i, j, k, l;
	int mas, tas;
	int tle, mle, len;
	string ot, nt;
	vector<int> tmp;
	
	freopen("1269.in" , "r", stdin);
	freopen("1269.out", "w", stdout);
	
	cin >> r;
	while(r --)
	{
		cin >> t >> n;
		memset(f, 0, sizeof(f));
		u.clear();
		
		for(i = 0;i < n;i ++)
		{
			cin >> w[i].o;
			w[i].n = w[i].o;
			sort(w[i].n.begin(), w[i].n.end());
			
			u[w[i].n].push_back(i);
		}
		
		for(i = 0, len = t.size();i < len;i ++)
			for(j = i, f[i] = INFINITE;j > -1;j --)
			{
				nt = ot = t.substr(j, i - j + 1);
				sort(nt.begin(), nt.end());
				tle =   ot .size();
				mle = u[nt].size();
				tmp = u[nt]       ;
				
				for(k = 0, mas = INFINITE;k < mle;k ++)
				{
					for(l = tas = 0;l < tle;l ++)
						if(w[tmp.at(k)].o[l] != ot[l])
							tas ++;
					mas = min(mas, tas);
				}
				f[i] = min(f[i], (j ? f[j - 1] : 0) + mas);
			}
		cout << (f[len - 1] == INFINITE ? -1 : f[len - 1]) << endl;
	}
	
	return 0;
}
