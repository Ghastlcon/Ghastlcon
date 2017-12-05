#include <iostream>
#include <algorithm>
#define N 120
#define MOD 10007
using namespace std;

int f[N];

void ExGCD(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        ExGCD(b, a % b, y, x);
        y -= x * (a / b);
    }

    return;
}

int Pow(int x, int y, int k)
{
    int s;

    for(s = 1;y;y >>= 1)
    {
        if(y & 1)
            s = (long long)s * x % k;
        x = (long long)x * x % k;
    }

    return s;
}

void Inverse(int n, int k)
{
    int i;

    for(i = 2, f[1] = 1;i <= n;i ++)
        f[i] = (long long)(k - k / i) * f[k % i] % k;

    return;
}

int main()
{
    int n, k;
    int i;

    cin >> n >> k;
    Inverse(n, k);
    for(i = 1;i <= n;i ++)
        cout << f[i] << ' ';
    
    return 0;
}
