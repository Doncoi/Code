#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n, m;

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
	while(scanf("%d", &n))
	{
		if(n == 42) return 0;
		printf("%d\n", n);
	}
}
