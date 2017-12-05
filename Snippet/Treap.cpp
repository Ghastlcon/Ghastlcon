#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

class Node
{
public:
    Node *s[2];
    int   v   ;
    int   e   ;
    int   w   ;
    int   z   ;

    Node(Node *l, Node *r, int _v, int _e, int _w, int _z) : v(_v), e(_e), w(_w), z(_z)
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
        z = Size(0) + Size(1) + w;

        return;
    }
};

Node *r;

void RotateTreap(Node *&x, bool k)
{
    Node *t;

    x -> s[!k] = (t = x -> s[!k]) -> s[k];
    t -> s[k] = x;

    x -> Update();
    t -> Update();
    x = t;

    return;
}

void InsertTreap(Node *&x, int v)
{
    if(!x)
        x = new Node(NULL, NULL, v, rand(), 1, 1);
    else if(x -> v == v)
        x -> w ++;
    else
    {
        InsertTreap(x -> s[x -> v < v], v);
        if(x -> s[x -> v < v] -> e < x -> e)
            RotateTreap(x, x -> v > v);
    }
    x -> Update();

    return;
}

void RemoveTreap(Node *&x, int v)
{
    int k;
    Node *t;

    if(x && x -> v == v)
        if(x -> w > 1)
            x -> w --;
        else if(!x -> s[0] || !x -> s[1])
        {
            t = x;
            x = x -> s[!x -> s[0]];
            
            delete t;
            return;
        }
        else
        {
            RotateTreap(x, (k = x -> s[0] -> e < x -> s[1] -> e));
            RemoveTreap(x -> s[k], v);
        }
    else if(x)
    {
        RemoveTreap(x -> s[k = x -> v < v], v);
        if(x -> s[k] && x -> s[k] -> e < x -> e)
            RotateTreap(x, x -> s[k] -> e < x -> e);
    }
    x -> Update();

    return;
}

bool FindTreap(Node *x, int v)
{
    for(;x;x = x -> s[x -> v < v])
        if(x -> v == v)
            return true;

    return false;
}

int KthTreap(Node *x, int k)
{
    int t;

    if(!x)
        return 0;
    t = x -> Size(0);

    if(k < t + 1     )
        return KthTreap(x -> s[0], k             );
    if(k > t + x -> w)
        return KthTreap(x -> s[1], k - t - x -> w);
    return x -> v;
}

void OutputTreap(Node *x)
{
    if(!x)
        printf("-1");
    else
    {
        putchar('(');
        OutputTreap(x -> s[0]);
        putchar(')');

        printf("%d",x -> v);

        putchar('(');
        OutputTreap(x -> s[1]);
        putchar(')');
    }

    return;
}

int main()
{
    int q, k;
    string s;

    cin >> q;
    while(q --)
    {
        cin >> s >> k;
        if(s == "Insert")
            InsertTreap(r, k);
        else if(s == "Kth")
            cout << KthTreap(r, k) << endl;
        else if(s == "Remove")
            RemoveTreap(r, k);
    }

    return 0;
}
