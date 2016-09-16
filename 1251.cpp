#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int gl[128], f[8];

void init(void)
{
	gl['1'] = gl['Q'] = gl['A'] = gl['Z'] = 0;
	
	gl['2'] = gl['W'] = gl['S'] = gl['X'] = 1;
	
	gl['3'] = gl['E'] = gl['D'] = gl['C'] = 2;
	
	gl['4'] = gl['R'] = gl['F'] = gl['V'] =
	gl['5'] = gl['T'] = gl['G'] = gl['B'] = 3;
	
	gl['6'] = gl['Y'] = gl['H'] = gl['N'] =
	gl['7'] = gl['U'] = gl['J'] = gl['M'] = 4;
	
	gl['8'] = gl['I'] = gl['K'] = gl[','] = 5;
	
	gl['9'] = gl['O'] = gl['L'] = gl['.'] = 6;
	
	gl['0'] = gl['P'] = gl[';'] = gl['/'] =
	gl['-'] = gl['='] = gl['['] = gl[']'] = gl['\''] = 7;
	
	return;
}

int main()
{
	string s;
	int i, l;
	
	freopen("1251.in" , "r", stdin);
	freopen("1251.out", "w", stdout);
	
	init();
	cin >> s;
	
	for(i = 0, l = s.size();i < l;i ++)
		f[gl[toupper(s[i])]] ++;
	for(i = 0;i < 8;i ++)
		cout << f[i] << endl;
	
	return 0;
}
