#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 500 + 5
#define MAXM

int n, m = 0, a[MAXN];

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
	for(int i = 1; i <= n; ++ i)
	{
		int x = read();
		if(x % 2) 
		{
			a[++ m] = x;
		}
	}

	std :: sort(a + 1, a + m + 1);
	for(int i = 1; i < m; ++ i)
	{
		std :: cout << a[i] << ',';
	}
	std :: cout << a[m];
}
