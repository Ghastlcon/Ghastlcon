#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

string D2X(int d, int n)
{
    string x;
    char s[2];
    
    for(x = "";d;d /= n)
    {
        s[0] = d % n + (d % n > 9 ? 55 : 48);
        s[1] = 0;
        x = s + x;
    }
    
    return x;
}

int X2D(string x, int n)
{
    int i, l, d;
    
    for(i = d = 0, l = x.size();i < l;i ++)
        d += (x[i] - (isalpha(x[i]) ? (isupper(x[i]) ? 55 : 87) : 48)) * pow((int)n, (int)(l - i - 1));
    
    return d;
}

int main()
{
    string x;
    
    cin >> x;
    cout << X2D(x, 2) << endl;
    
    return 0;
}
