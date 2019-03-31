
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000 + 5

int n, m, i, j, k;
int a[MAXN], b[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	while(std :: cin >> n && n)
	{
		while(std :: cin >> b[0] && b[0])
		{
			for(j = 1; j < n; ++ j)
			{
				b[j] = read();
			}
			for(i = 1, j = 0, k = 0; i <= n && j < n; ++ i, ++ k)
			{
				a[k] = i;
				while(a[k] == b[j])
				{
					if(k > 0) -- k;
					else
					{
						a[k] = 0; -- k;
					}
					++ j;
					if(k == -1) break;
				}
			}

			if(j == n) std :: cout << "Yes" << std :: endl;
			else std :: cout << "No" << std :: endl;
		}
		std :: cout << std :: endl;
	}
}
