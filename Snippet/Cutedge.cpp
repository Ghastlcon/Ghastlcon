#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define N 120
using namespace std;

vector<int> e[N];
int d[N], l[N];
set<pair<int, int> > o;

void CutedgeFind(int x, int p)
{
    static int t = 0;
    int i;

    d[x] = l[x] = ++ t;
    for(i = 0;i < (signed)e[x].size();i ++)
        if(!d[e[x].at(i)])
        {
            CutedgeFind(e[x].at(i), x);
            l[x] = min(l[x], l[e[x].at(i)]);

            if(l[e[x].at(i)] > d[x])
                o.insert(make_pair(x, e[x].at(i)));
        }
        else if(e[x].at(i) != p)
            l[x] = min(l[x], d[e[x].at(i)]);

    return;
}

vector<pair<int, int> > Cutedge()
{
    vector<pair<int, int> > u;
    set<pair<int, int> >::iterator it;

    CutedgeFind(0, 0);
    for(it = ::o.begin();it != ::o.end();it ++)
        u.push_back(*it);

    return u;
}

int main()
{
    int n, m, u, v;
    vector<pair<int, int> > ans;

    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ans = Cutedge();
    for_each(ans.begin(), ans.end(), [](pair<int, int> &x) -> void {cout << x.first << '-' << x.second << endl;});

    return 0;
}
