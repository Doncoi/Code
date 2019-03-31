#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n, m, ans;

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
    n = read();
	ans = 2147483647;
	for(int i = 1, j, k, tmp; i < n; ++ i)
	{
		j = n - i, k = i, tmp = 0;
		while(j) {tmp += j % 10; j /= 10;}
		while(k) {tmp += k % 10; k /= 10;}
		ans = min(ans, tmp);
	}

	std :: cout << ans << std :: endl;
}