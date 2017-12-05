#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

class Node
{
public:
    Node *s[2];
    int   v   ;
    int   z   ;
    int   a   ;
    bool  f   ;

    Node(Node *l, Node *r, int _v, int _z) : v(_v), z(_z), a(0), f(false)
    {
        s[0] = l;
        s[1] = r;

        return;
    }

    int Size(bool k)
    {
        return s[k] ? s[k] -> z : 0;
    }

    void Update(void)
    {
        z = Size(0) + Size(1) + 1;
        if(f)
        {
            if(s[0])
                s[0] -> f ^= 1;
            if(s[1])
                s[1] -> f ^= 1;
            swap(s[0], s[1]);
            f = false;
        }
        if(a)
        {
            if(s[0])
                s[0] -> a += a;
            if(s[1])
                s[1] -> a += a;
            v += a;
            a = 0;
        }

        return;
    }
};

int n;
Node *r;

void BuildSplay(Node *&x, int l, int r)
{
    if(l > r)
        return;

    x = new Node(NULL, NULL, (l + r) / 2, 1);
    if(l >= r)
        return;

    BuildSplay(x -> s[0],  l             , (l + r) / 2 - 1);
    BuildSplay(x -> s[1], (l + r) / 2 + 1,      r         );
    x -> Update();

    return;
}

void RotateSplay(Node *&x, bool k)
{
    Node *t;

    x -> s[!k] = (t = x -> s[!k]) -> s[k];
    t -> s[k] = x;

    x -> Update();
    t -> Update();
    x = t;

    return;
}

void SplaySplay(Node *&x, int k)
{
    int t, p, d;

    x -> Update();
    t = x -> Size(0) + 1;
    if(k != t)
    {
        x -> s[k > t] -> Update();
        p = x -> s[k > t] -> Size(0) + 1;
        d = k - (k > t ? t : 0);
        
        if(d != p)
        {
            SplaySplay(x -> s[k > t] -> s[d > p], d - (d > p ? p : 0));
            if((k > t) == (d > p))
                RotateSplay(x, k < t);
            else
                RotateSplay(x -> s[k > t], k > t);
        }
        RotateSplay(x, k < t);
    }

    return;
}

void FlipSplay(int x, int y)
{
    SplaySplay(r        , x                         );
    SplaySplay(r -> s[1], y + 2 - (r -> Size(0) + 1));
    r -> s[1] -> s[0] -> f ^= 1;

    return;
}

void AddSplay(int x, int y, int v)
{
    SplaySplay(r        , x                         );
    SplaySplay(r -> s[1], y + 2 - (r -> Size(0) + 1));
    r -> s[1] -> s[0] -> a += v;

    return;
}

void OutputSplay(Node *x, int n, int v)
{
    if(!x)
        return;

    x -> Update();
    OutputSplay(x -> s[0], n, v);

    v += x -> Size(0) + 1;
    if(v > 1 && v <= n + 1)
        cout << x -> v << ' ';

    OutputSplay(x -> s[1], n, v);

    return;
}

int main()
{
    int n, q, x, y, v;
    string s;

    cin >> n >> q;
    BuildSplay(r, 0, n + 1);

    while(q --)
    {
        cin >> s >> x >> y;
        if(s == "Flip")
            FlipSplay(x + 1, y + 1);
        else if(s == "Add")
        {
            cin >> v;
            AddSplay(x + 1, y + 1, v);
        }
    }
    OutputSplay(r, n, 0);

    return 0;
}
