#include <iostream>
#include <algorithm>
#include <vector>
#define N 120
using namespace std;

int f[N];

void InitKMP(string p)
{
    int i, j, m;

    for(i = 1, m = p.size();i < m;i ++)
    {
        j = f[i];
        while(j && p[i] != p[j])
            j = f[j];
        f[i + 1] = (p[i] == p[j] ? j + 1 : 0);
    }

    return;
}

vector<int> MatchKMP(string t, string p)
{
    int n, m;
    int i, j;
    vector<int> v;

    for(n = t.size(), m = p.size(), i = j = 0;i < n;i ++)
    {
        while(j && p[j] != t[i])
            j = f[j];
        j += p[j] == t[i];
        if(j == m)
            v.push_back(i - m + 1);
    }

    return v;
}

int main()
{
    string t, p;
    vector<int> v;
    int i;

    cin >> t >> p;
    InitKMP(p);
    v = MatchKMP(t, p);
    for(i = 0;i < (signed)v.size();i ++)
        cout << v.at(i) << ' ';
    cout << endl;

    return 0;
}
