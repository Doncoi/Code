#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000000
#define MOD 1000000007

int s, a, d;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') res = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
    return res * flg;
}

long long calc()
{
    long long res_1, res_2, ans;
    res_1 = d * d;
    res_1 = res_1 * 6;
    res_2 = a * d;
    res_2 = res_2 * 7;
    ans = res_1 + res_2;
    return ans;
}

int main()
{
    s = read(), d = 129, a = 0;
    for(a = 1; a <= s / 2; ++ a)
    {
        //std :: cout << a << " " << d << std :: endl;
        while(calc() > s) -- d;
        if(calc() == s) std :: cout << "a = " << a << " d = " << d << " ans = " << (long long)a * a * 2 % MOD << std :: endl;
        if(calc() < s) ++ d;
    }
}
