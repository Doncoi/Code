#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MOD 2048

int n;
long long tmp, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    while(scanf("%d", &n))
    {
    	n = n - 1;
        tmp = (n % MOD) * (n % MOD) % MOD;
		tmp = tmp + ((n % MOD) * 8) % MOD;
		tmp = tmp + 18 % MOD;
		tmp = tmp * ( (n + 1) % MOD ) % MOD;
		ans = tmp / 6;
		std :: cout << ans << std :: endl; 
    } 
}
