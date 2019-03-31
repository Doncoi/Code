#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000

int n, m;
int a[MAXN];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int main()
{
	for(int i = 0; i < MAXN; ++ i)
	{
		int tmp = i;
		while(tmp)
		{
			a[i] += tmp % 10, tmp /= 10;
		}
	}

	n = read(), m = read();
	long long sum = 0;
	for(int i = n; i <= m; ++ i)
	{
		sum += a[i % MAXN] + a[i / MAXN];
	}
	std :: cout << sum << std :: endl;
} 
