#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define N 1000020
using namespace std;

bool d[N];
int p[N];

int Prime(int x)
{
    int i, s;
    
    if(x < 2)
        return 0;
    if(x == 2 || x == 3)
        return 1;
    if(!(x % 2))
        return 0;
    
    for(i = 3, s = sqrt(x) + 1;i <= s;i ++)
        if(!(x % i))
            return 0;
    return 1;
}

vector<int> PrimeSheet(int n)
{
    int i, j, u;
    vector<int> ans;
    
    for(i = 2, u = 0;i <= n;i ++)
    {
        if(!d[i])
            p[++ u] = i;

        for(j = 1;j <= u && i * p[j] <= n;j ++)
        {
            d[i * p[j]] = true;
            if(!(i % p[j]))
                break;
        }
    }
    for(i = 0;i <= n;i ++)
        if(p[i])
            ans.push_back(p[i]);
    
    return ans;
}

int main()
{
    int x;
    vector<int> u;
    
    cin >> x;
    u = PrimeSheet(x);
    for_each(u.begin(), u.end(), [](int &x) -> void {cout << x << ' ';});
    
    return 0;
}
