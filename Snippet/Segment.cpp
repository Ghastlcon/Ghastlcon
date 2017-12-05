#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#define N 120
using namespace std;

pair<int, int> f[N * 4];

void BuildSegment(vector<int> &x, int i, int l, int r)
{
    f[i].second = 0;
    if(l >= r)
    {
        f[i].first = x.at(l);

        return;
    }

    BuildSegment(x, i * 2    , l              , (l + r) / 2);
    BuildSegment(x, i * 2 + 1, (l + r) / 2 + 1, r          );
    f[i].first = f[i * 2].first + f[i * 2 + 1].first;

    return;
}

void Maintain(int i, int l, int r)
{
    int m = (l + r) / 2;

    f[i * 2    ].first  += (m - l + 1) * f[i].second;
    f[i * 2 + 1].first  += (r - m    ) * f[i].second;
    f[i * 2    ].second +=               f[i].second;
    f[i * 2 + 1].second +=               f[i].second;
    f[i].second = 0;

    return;
}

int SumSegment(int i, int l, int r, int s, int t)
{
    if(s <= l && t >= r)
        return f[i].first;
    if(s > r || t < l)
        return 0;
    if(f[i].second)
        Maintain(i, l, r);

    return SumSegment(i * 2, l, (l + r) / 2, s, t) + SumSegment(i * 2 + 1, (l + r) / 2 + 1, r, s, t);
}

void AddSegment_Point(int i, int l, int r, int p, int v)
{
    if(l > p || r < p)
        return;
    if(l == p && r == p)
    {
        f[i].first += v;
        return;
    }

    AddSegment_Point(i * 2    , l, (l + r) / 2    , p, v);
    AddSegment_Point(i * 2 + 1, (l + r) / 2 + 1, r, p, v);
    f[i].first = f[i * 2].first + f[i * 2 + 1].first;

    return;
}

void AddSegment_Chunk(int i, int l, int r, int s, int t, int v)
{
    if(s > r || t < l)
        return;
    if(s <= l && t >= r)
    {
        f[i].first  += (r - l + 1) * v;
        f[i].second +=               v;

        return;
    }
    if(f[i].second)
        Maintain(i, l, r);

    AddSegment_Chunk(i * 2    , l              , (l + r) / 2    , s, t, v);
    AddSegment_Chunk(i * 2 + 1, (l + r) / 2 + 1, r              , s, t, v);
    f[i].first = f[i * 2].first + f[i * 2 + 1].first;

    return;
}

/*
void Maintain(int i, int l, int r)
{
    int m = (l + r) / 2;

    f[i * 2    ].first  = (m - l + 1) * f[i].second;
    f[i * 2 + 1].first  = (r - m    ) * f[i].second;
    f[i * 2    ].second =               f[i].second;
    f[i * 2 + 1].second =               f[i].second;
    f[i].second = 0;

    return;
}

void SetSegment(int i, int l, int r, int s, int t, int v)
{
    if(s > r || t < l)
        return;
    if(s <= l && t >= r)
    {
        f[i].first  = (r - l + 1) * v;
        f[i].second =               v;

        return;
    }
    if(f[i].second)
        Maintain(i, l, r);

    SetSegment(i * 2    , l              , (l + r) / 2    , s, t, v);
    SetSegment(i * 2 + 1, (l + r) / 2 + 1, r              , s, t, v);
    f[i].first = f[i * 2].first + f[i * 2 + 1].first;

    return;
}*/

int main()
{
    vector<int> x;
    int n, q;
    int u, v, w;
    string s;

    cin >> n;
    for(u = 0;u < n;u ++)
    {
        cin >> v;
        x.push_back(v);
    }
    BuildSegment(x, 1, 0, n - 1);

    cin >> q;
    while(q --)
    {
        cin >> s >> u >> v;
        if(u > v)
            swap(u, v);

        if(s == "Modify")
        {
            cin >> w;
            AddSegment_Chunk(1, 0, n - 1, u, v, w);
        }
        else if(s == "Query")
            cout << SumSegment(1, 0, n - 1, u, v) << endl;
    }

    return 0;
}
