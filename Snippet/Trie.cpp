#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 300020
#define M 26
#define ID(x) ((x) - 97)
#define MOD 20071027
using namespace std;

class Sigma
{
public:
    int f[M];
    int v;

    Sigma(void)
    {
        memset(f, 0, sizeof(f));
        v = 0;

        return;
    }
};

vector<Sigma> f;
int g[N];

void InitTrie(void)
{
    f.push_back(Sigma());

    return;
}

void InsertTrie(string s, int v)
{
    int i, j;

    for(i = j = 0;i < (signed)s.size();i ++)
    {
        if(!f.at(j).f[ID(s[i])])
        {
            f.at(j).f[ID(s[i])] = f.size();
            f.push_back(Sigma());
        }
        j = f.at(j).f[ID(s[i])];
    }
    f.at(j).v = v;

    return;
}

int main()
{
    string s, t;
    int n;
    int i, j, k, r;

    for(r = 1;cin >> s;r ++)
    {
        f.clear();
        memset(g, 0, sizeof(g));
        InitTrie();

        cin >> n;
        while(n --)
        {
            cin >> t;
            InsertTrie(t, 1);
        }

        g[s.size()] = 1;
        for(i = s.size() - 1;i > -1;i --)
        {
            for(j = i, k = 0;j < (signed)s.size();j ++)
                if(f.at(k).f[ID(s[j])])
                {
                    k = f.at(k).f[ID(s[j])];
                    if(f.at(k).v)
                        g[i] = (g[i] + g[j + 1]) % MOD;
                }
                else
                    break;
        }
        cout << "Case " << r << ": " << g[0] << endl;
    }

    return 0;
}
