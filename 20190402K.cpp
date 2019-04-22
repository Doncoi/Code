
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5
 
char ch[MAXN];
int m, next[MAXN];
 
void getNext(char *B)
{
    next[1] = 0;
    int pre = 0;
    for (int i = 2; i <= m; ++i)
    {
        while (pre > 0 && B[pre + 1] != B[i])
            pre = next[pre];
        if (B[pre + 1] == B[i])
            ++pre;
        next[i] = pre;
    }
}
 
int read()
{
    int res = 0, flg = 1;
    char chr = getchar();
    while (!isdigit(chr))
    {
        if (chr == '-')
            flg = -1;
        chr = getchar();
    }
    while (isdigit(chr))
    {
        res = res * 10 + chr - '0';
        chr = getchar();
    }
    return (res * flg);
}
 
int main()
{
    while (std ::cin >> ch)
    {
        m = strlen(ch);
        if(m == 1) 
        {
            std :: cout << m << std :: endl;
            continue;
        }
        if(m == 2)
        {
            if(ch[0] == ch[1]) std :: cout << 1 << std :: endl;
            else std :: cout << 2 << std :: endl;
            continue;
        }
        getNext(ch);
         
        /*
        for(int i = 1; i <= m; ++ i)
        {
            std :: cout << next[i] << " ";
        }
        std :: cout << std :: endl;
        */
        if ((next[m - 1] + 1) % (m - next[m - 1] - 1) != 0)
        {
            std ::cout << m << std ::endl;
            continue;
        }
        std ::cout << m - next[m - 1] - 1 << std ::endl;
    }
}