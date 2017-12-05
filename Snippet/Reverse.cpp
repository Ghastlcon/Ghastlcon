#include <iostream>
#include <algorithm>
using namespace std;

string Reverse(string x)
{
    int i, j;
    
    for(i = 0, j = x.size() - 1;i < j;i ++, j --)
        swap(x[i], x[j]);
    
    return x;
}

int main()
{
    string x;
    
    cin >> x;
    cout << Reverse(x) << endl;
    
    return 0;
}
