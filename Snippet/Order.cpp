#include <iostream>
#include <algorithm>
#include <utility>
#define N 120
using namespace std;

class Queue
{
private:
    pair<int, int> f[N];
    int l, r;

public:
    Queue() : l(0), r(0)
    {
        return;
    }

    bool Empty(void)
    {
        return l == r;
    }

    pair<int, int> Back (void)
    {
        return f[r - 1];
    }

    pair<int, int> Front(void)
    {
        return f[l    ];
    }

    void Push_Back(pair<int, int> x)
    {
        f[r ++] = x;

        return;
    }

    void Pop_Back (void)
    {
        r --;

        return;
    }

    void Pop_Front(void)
    {
        l ++;

        return;
    }
};

int a[N];
Queue q;

void PushOrder(int x)
{
    while(!q.Empty() && q.Back().first < a[x])
        q.Pop_Back();
    q.Push_Back(make_pair(a[x], x));

    return;
}

void PopOrder(int x)
{
    if(q.Front().second == x)
        q.Pop_Front();

    return;
}

int MaxOrder(void)
{
    return q.Front().first;
}

int main()
{
    int n, k;
    int i;

    cin >> n >> k;
    for(i = 0;i < n;i ++)
    {
        cin >> a[i];
        if(i < k)
            PushOrder(i);
    }

    for(i = k;i < n;i ++)
    {
        cout << MaxOrder() << endl;
        PopOrder (i);
        PushOrder(i);
    }
    cout << MaxOrder() << endl;

    return 0;
}
