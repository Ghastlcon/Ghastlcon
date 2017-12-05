#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define N 120
using namespace std;

int f[N], c;

int Siftup  (int x)
{
    for(;x        >  1 &&                   f[x >> 1] > f[x]                                                                              ;swap(f[x], f[x >> 1])                                  , x = (x >> 1))
        ;

    return x << 1;
}

int Siftdown(int x)
{
    for(;(x << 1) <= c && ((x << 1) == c && f[x << 1] < f[x] ? (swap(f[x], f[x << 1]), 1) : 1) && f[x] > min(f[(x << 1)], f[(x << 1) + 1]);x = (x << 1) + (f[(x << 1)] > f[(x << 1) + 1]), swap(f[x], f[x >> 1]))
        ;
    return x << 1;
}

void AddHeap(int x)
{
    f[++ c] = x;
    Siftup(c);

    return;
}

void RemoveHeap(int x)
{
    int t;

    f[x] = -1;
    t = Siftdown(x);
    swap(f[t], f[c --]);
    Siftup(t);

    return;
}

int MaxHeap(void)
{
    return f[1];
}

int main()
{
    int q, x;
    string s;

    memset(f, -1, sizeof(f));
    cin >> q;
    while(q --)
    {
        cin >> s;
        if(s == "Query")
            cout << MaxHeap() << endl;
        else if(s == "Add")
        {
            cin >> x;
            AddHeap(x);
        }
        else if(s == "Remove")
        {
            cin >> x;
            RemoveHeap(x);
        }
    }

    return 0;
}
