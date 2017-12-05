#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int queen[8] = {0, 1, 2, 3, 4, 5, 6, 7};next_permutation(queen, queen + 8);)
        if((bitset<15>(accumulate(queen, queen + 8, make_pair(0, 0), [](pair<int, int> a, int b){return make_pair((1 << (b + a.second)) | a.first, a.second + 1);}).first).count() == 8) && (bitset<15>(accumulate(queen, queen + 8, make_pair(0, 0), [](pair<int, int> a, int b){return make_pair((1 << (7 + b - a.second)) | a.first, a.second + 1);}).first).count() == 8))
            cout << queen[0] << queen[1] << queen[2] << queen[3] << queen[4] << queen[5] << queen[6] << queen[7] << endl;
    return 0;
}
