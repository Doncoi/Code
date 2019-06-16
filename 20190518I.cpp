#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n, a, b, c, d;
int cnt, ans_1, ans_2;

int min(int x, int y)
{
    return x < y ? x : y;
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') res = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
    return res * flg;
}

int main()
{
    n = read(), a = read(), b = read(), c = read(), d = read();
    for(int i = 1; i <= n; ++ i)
    {
        cnt += read();
    }
    if(cnt >= a) ans_1 = cnt - b;
    else ans_1 = cnt;
    if(cnt >= c) ans_2 = cnt - d;
    else ans_2 = cnt;

    std :: cout << min(ans_1, ans_2);
}