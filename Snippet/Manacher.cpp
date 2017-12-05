#include <iostream>
#include <algorithm>
#include <string>
#define N 120
using namespace std;

int f[N << 1];

int main()
{
    string s;
    int i, p;

    cin >> s;
    for(i = 0;i < (signed)s.size() + 1;i += 2)
        s.insert(i, "#");

    for(i = p = 0;i < (signed)s.size();i ++)
    {
        f[i] = (i < p + f[p] ? min(f[p * 2 - i], p + f[p] - i) : 1);
        while(i - f[i] > -1 && i + f[i] < (signed)s.size() && s[i - f[i]] == s[i + f[i]])
            f[i] ++;
        if(i + f[i] > p + f[p])
            p = i;
    }

    for(i = p = 0;i < (signed)s.size();i ++)
        p = max(p, f[i]);
    cout << p - 1 << endl;

    return 0;
}
