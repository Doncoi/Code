#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

int s, p, s1, p1, s2, p2;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    p1 = read(), s1 = read();
    s2 = read(), p2 = read();
    s = s1 + s2, p = p1 + p2;
    if(s > p) 
    {
        std :: cout << "Esteghlal" << std :: endl;
    } 
    else if(s < p)
    {
        std :: cout << "Persepolis" << std :: endl;
    }
    else
    {
        if(s1 > p2) 
        {
            std :: cout << "Esteghlal" << std :: endl;
        }
        else if(s1 < p2)
        {
            std :: cout << "Persepolis" << std :: endl;
        }
        else
        {
            std :: cout << "Penalty" << std :: endl;
        }
    }
}
