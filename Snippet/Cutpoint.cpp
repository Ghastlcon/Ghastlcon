#include <iostream>
#include <algorithm>
#include <vector>
#define N 120
using namespace std;

vector<int> e[N];
int d[N], l[N];
bool o[N];

void CutpointFind(int x, int p)
{
    static int t = 0;
    int i, h;

    d[x] = l[x] = ++ t;
    for(i = h = 0;i < (signed)e[x].size();i ++)
        if(!d[e[x].at(i)])
        {
            h ++;
            CutpointFind(e[x].at(i), x);
            l[x] = min(l[x], l[e[x].at(i)]);

            if((x && l[e[x].at(i)] >= d[x]) || (!x && h == 2))
                o[x] = true;
        }
        else if(e[x].at(i) != p)
            l[x] = min(l[x], d[e[x].at(i)]);

    return;
}

vector<int> Cutpoint(int n)
{
    int i;
    vector<int> u;

    CutpointFind(0, 0);
    for(i = 0;i < n;i ++)
        if(o[i])
            u.push_back(i);

    return u;
}

int main()
{
    int n, m, u, v;
    vector<int> ans;

    cin >> n >> m;
    while(m --)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ans = Cutpoint(n);
    for_each(ans.begin(), ans.end(), [](int &x) -> void {cout << x << ' ';});

    return 0;
}
