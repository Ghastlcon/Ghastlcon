#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 1020
#define K 10
#define INFINITE 999999999
using namespace std;

class Queue
{
private:
    int f[N];
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

    int Size(void)
    {
        return r - l;
    }

    int Back (int v = 0)
    {
        return f[r - 1 - v];
    }

    int Front(int v = 0)
    {
        return f[l    + v];
    }

    void Push_Back(int x)
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

int n, k;
int a[N];
int f[N], g[N], h[N];
int b[N];
Queue q;

int Y(int j, int t)
{
    return (f[j] - h[j] + (j - 1) * g[j]) - (f[t] - h[t] + (t - 1) * g[t]);
}

int X(int j, int t)
{
    return j - t;
}

int F(int i)
{
    return g[i - 1];
}

int D(int i, int j)
{
    return f[j] + h[i - 1] - h[j] - (g[i - 1] - g[j]) * (j - 1);
}

int Solve(void)
{
    int i, j;
    int v, o;

    for(i = 0;i < N;i ++)
        f[i] = INFINITE;
    f[1] = 0;

    for(i = 1;i <= n;i ++)
    {
        g[i] = g[i - 1] + a[i];
        h[i] = h[i - 1] + (i - 1) * a[i];
    }

    for(j = 2;j <= k;j ++)
    {
        q = Queue();
        q.Push_Back(0);

        for(i = 1;i <= n;i ++)
        {
            while(q.Size() > 1 && Y(q.Front(1), q.Front()) <= F(i) * X(q.Front(1), q.Front()))
                q.Pop_Front();
            b[i] = D(i, q.Front());

            while(q.Size() > 1 && Y(i, q.Back()) * X(q.Back(), q.Back(1)) <= Y(q.Back(), q.Back(1)) * X(i, q.Back()))
                q.Pop_Back();
            q.Push_Back(i);
        }
        for(i = 1;i <= n;i ++)
            f[i] = b[i];
    }

    for(i = n, o = INFINITE, v = 0;i >= k;i --)
    {
        v += g[n] - g[i];
        o = min(o, f[i] + v);
    }

    return o;
}

int main()
{
    int i;

    cin >> n >> k;
    for(i = 1;i <= n;i ++)
        cin >> a[i];
    cout << Solve() << endl;

    return 0;
}
