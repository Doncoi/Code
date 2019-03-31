#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000000 + 7

bool vis[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int GCD(int x, int y)
{
	return !y ? x : GCD(y, x % y);
}

void solve(int t)
{
	int n, m, x, y, z;
	int tmp = (int)std :: sqrt((double)t);
	int ans_1 = 0, ans_2 = 0;

	for(n = 1; n <= tmp; ++ n)
	{
		for(m = n + 1; m <= tmp; ++ m)
		{
			if(m * m + n * n > t) 
			{
				break;			
			}

			if(n % 2 != m % 2)
			{
				if(GCD(m, n) == 1)
				{
					x = m * m - n * n;
					y = m * n * 2;
					z = m * m + n * n;
					++ ans_1;

					for(int i = 1; ; ++ i)
					{
						if(i * z > t) 
						{
							break;
						}

						vis[i * x] = vis[i * y] = vis[i * z] = 1;
					}
				}
			}
		}
	}

	for(int i = 1; i <= t; ++ i)
	{
		if(! vis[i])
		{
			++ ans_2;
		}
	}

	std :: cout << ans_1 << " " << ans_2 << std :: endl;
}

int main()
{
    int t;
    while(std :: cin >> t)
    {
    	solve(t);
    }

    return 0;
}
