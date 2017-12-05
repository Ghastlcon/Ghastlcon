#include <iostream>
#include <algorithm>
#include <cstdlib>
#pragma GCC optimize("O3")
using namespace std;

extern int Main() __asm__ ("Main");

void DFS(int x, int c)
{
    if(x != c)
        DFS(x + 1, c);

    return;
}

int Main()
{
    DFS(0, 1000000);

    exit(0);
}

int main()
{
    __asm__ __volatile__("movq %0, %%rsp\npushq $exit\njmp Main\n" :: "r"((char *)malloc(64 << 20) + (64 << 20)));

    return 0;
}
