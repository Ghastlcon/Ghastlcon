char *strrev(char *s)
{
    char *h = s, *t = s, ch;

    while(*t ++)
        ;
    t -= 2;

    while(h < t)
    {
        ch = *h;
        *h ++ = *t;
        *t -- = ch;
    }

    return s;
}

char *itoa(int num, char *str, int radix)
{
	char string[40] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ptr;
	int i, j, temp;
	
    if(!num)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
	
    ptr = str;
    while(num)
    {
        *ptr ++ = string[num % radix];
        num /= radix;
        if(num < radix)
        {
            *ptr ++ = string[num];
            *ptr = '\0';
            break;
        }
    }

    j = ptr - str - 1;

    for(i = 0;i < (ptr - str) / 2;i ++)
    {
        temp = str[i];
        str[i] = str[j];
        str[j --] = temp;
    }

    return str;
}
