#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10000 + 5

int n, q, l, r;
std :: string s;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') res = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
    return res * flg;
}

int main()
{
    std :: cin >> n >> q >> s;
    for(int i = 1; i <= q; ++ i)
    {
        l = read(), r = read();
        int dis = r - l + 1, res;
        res = dis * (dis + 1) / 2;
        std :: cout << res << std :: endl;
    }
}