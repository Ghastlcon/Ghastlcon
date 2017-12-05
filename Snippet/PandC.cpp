#include <iostream>
#include <algorithm>
#define N 120
#define MOD 10007
using namespace std;

int c[N][N];

int P(int n, int m)
{
    int i;
    
    for(i = 1;m --;)
        i = (i * ((n - m) % MOD)) % MOD;
    
    return i;
}

void C(int n)
{
    int i, j;
    
    for(i = 0;i <= n;i ++)
        for(j = c[i][0] = c[i][i] = 1;j < i;j ++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    
    return;
}

int main()
{
    
    
    return 0;
}
