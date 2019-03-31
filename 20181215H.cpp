#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 50 + 5

int m, n, w;
int rec[MAXN][MAXN];
long long res;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    m = read(), n = read(), w = read();
    for(int i = 1; i <= m; ++ i)
    {
    	for(int j = 1; j <= n; ++ j)
    	{
    		rec[i][j] = read();
    		res += rec[i][j];
    	}
    }

    if(res >= w)
    {
    	std :: cout << "NO" << std :: endl;
    }
    else
    {
    	std :: cout << "YES" << std :: endl;
    }
}
