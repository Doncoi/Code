#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int T, n, len, ant;
int left, right;
int minn, maxn;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}
 
int main()
{
	T = read();
	while(T --)
	{
		minn = maxn = -1;
		len = read(), n = read();
		while(n--)
		{
			ant = read();
			left = ant, right = len - ant;
			if (left < right)
			{
				if (left > minn) minn = left;
				if (right > maxn) maxn = right;
			}
			else
			{
				if (right > minn) minn = right;
				if (left > maxn) maxn = left;
			}
		}
		std :: cout << minn << " " << maxn << std :: endl;
	}
}
