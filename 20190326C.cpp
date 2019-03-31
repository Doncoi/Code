#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 200000 + 5

int n, m, cnt;
long long ans;
std :: string s;

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	std :: cin >> s;
    for(int i = 0; i < s.length(); ++ i)
    {
        if(s[i] == 'B') ++ cnt;
        else ans += cnt;
    }

    std :: cout << ans << std :: endl;
}