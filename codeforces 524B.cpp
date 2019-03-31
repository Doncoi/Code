#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 
#define MAXM

int q, x, y;

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int main()
{
	q = read();
	while(q --)
	{
		x = read(), y = read();
		if(x == y)
		{
			if(x % 2)
			{
				printf("%d\n", x * -1);
			}
			else
			{
				printf("%d\n", x);
			}
		}
		else
		{
			if(x % 2)
			{
				if(y % 2)
				{
					int res = x * -1;
					res += ((y - x) / 2) * -1;
					printf("%d\n", res);
				}
				else
				{
					int res = (y - x + 1) / 2;
					printf("%d\n", res);
				}
			}
			else
			{
				if(y % 2)
				{
					int res = (y - x + 1) / 2 * -1;
					printf("%d\n", res);
				}
				else
				{
					int res = x;
					res += (y - x) / 2;
					printf("%d\n", res); 
				}
			}
		}
	}
}
