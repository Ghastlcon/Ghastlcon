/*Hash prime table:
 lwr  upr      %err      prime
2^ 5 2^ 6 10.416667         53
2^ 6 2^ 7  1.041667         97
2^ 7 2^ 8  0.520833        193
2^ 8 2^ 9  1.302083        389
2^ 9 2^10  0.130208        769
2^10 2^11  0.455729       1543
2^11 2^12  0.227865       3079
2^12 2^13  0.113932       6151
2^13 2^14  0.008138      12289
2^14 2^15  0.069173      24593
2^15 2^16  0.010173      49157
2^16 2^17  0.013224      98317
2^17 2^18  0.002543     196613
2^18 2^19  0.006358     393241
2^19 2^20  0.000127     786433
2^20 2^21  0.000318    1572869
2^21 2^22  0.000350    3145739
2^22 2^23  0.000207    6291469
2^23 2^24  0.000040   12582917
2^24 2^25  0.000075   25165843
2^25 2^26  0.000010   50331653
2^26 2^27  0.000023  100663319
2^27 2^28  0.000009  201326611
2^28 2^29  0.000001  402653189
2^29 2^30  0.000011  805306457
2^30 2^31  0.000000 1610612741
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define P 1572869
#define K 769
using namespace std;

pair<int, int> f[P];

void AddHash(int x)
{
    int p;

    for(p = x % P;f[p].first != x && f[p].second;p = (p + (x % K) + 1) % P)
        ;
    f[p].first = x;
    f[p].second ++;

    return;
}

int GetHash(int x)
{
    int p;

    for(p = x % P;f[p].first != x && f[p].second;p = (p + (x % K) + 1) % P)
        ;

    return f[p].second;
}

int main()
{
    int x;

    while(true)
    {
        cin >> x;
        AddHash(x);
        cout << GetHash(x) << endl;
    }

    return 0;
}