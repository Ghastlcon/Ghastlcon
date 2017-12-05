#include <iostream>
#include <algorithm>
#define MOD 10007
using namespace std;

int l[MOD + 1], r[MOD + 1];

int C(int n, int m)
{
    return m > n ? 0 : (long long)l[n] * r[n - m] % MOD * r[m] % MOD;
}

int Lucas(int n, int m)
{
    return !m ? 1 : (long long)C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
}

void InitLR()
{
    int i;

    l[0] = r[0] = l[1] = r[1] = 1;
    for(i = 2;i <= MOD;i ++)
        r[i] = (long long)(MOD - MOD / i) * r[MOD % i] % MOD;

    for(i = 2;i <= MOD;i ++)
    {
        l[i] = (long long)l[i - 1] *   i  % MOD;
        r[i] = (long long)r[i - 1] * r[i] % MOD;
    }

    return;
}

int main()
{
    int n, m;

    InitLR();
    cin >> n >> m;
    cout << Lucas(n, m) << endl;
    
    return 0;
}
