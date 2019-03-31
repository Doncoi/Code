#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5
#define MAXM 100000000

int n, minn = MAXM;
long long ans;
int a[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
    n = read();
    for(int i = 1; i <= n; ++ i)
    {
    	a[i] = read();
    	ans += a[i];
    	minn = min(minn, a[i]);
    }

    ans += (long long)((n - 2) * minn);
    std :: cout << ans << std :: endl; 
}
