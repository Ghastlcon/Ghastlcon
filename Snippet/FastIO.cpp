#include <cstdio>
#include <cctype>

char b[1 << 15 | 1], *p = b + 32768;
#define Getchar() (p >= b + 32768 ? (b[fread(b, sizeof(char), 1 << 15, stdin)] = EOF, *((p = b) ++)) : *(p ++))

int Scan(void)
{
    int f, s;
    char c;

    for(s = 0, f = 1;(c = Getchar()) != EOF && !isdigit(c);f = (c == '-' ? -1 : f))
        ;
    do
        s = s * 10 + c - 48;
    while((c = Getchar()) != EOF && isdigit(c));

    return s * f;
}

void Print(int x)
{
    static int b[10];
    int c;

    if(x < 0)
    {
        putchar('-');
        x = -x;
    }

    if(!x)
        putchar('0');
    else
    {
        for(c = 0;x;x /= 10)
            b[c ++] = x % 10;
        while(c --)
            putchar(b[c] + 48);
    }

    return;
}

int main()
{
    int x;

    while(x = Scan(), x)
        Print(x);

    return 0;
}
