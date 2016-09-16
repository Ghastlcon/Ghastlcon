#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int f[120];

int main()
{
    int n;
    int i, j, k, g;
    
    freopen("1274.in" , "r", stdin);
    freopen("1274.out", "w", stdout);
    
    cin >> n;
    
    for(i = 2, f[1] = 1;i <= n;i ++)
        for(j = 1;j < 6;j ++)
            if(i >= j && !f[i - j])
            {
                f[i] = 1;
                break;
            }
    cout << f[n] << endl;

    return 0;
}
