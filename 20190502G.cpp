#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int T, n, tot, minn;
int a[MAXN];
int prime[1000 + 5], vis[1000 + 5];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

void euler(int n) {
	for (int i = 2; i <= n; i ++) 
	{
		if (!vis[i]) prime[++ tot] = i;
		for (int j = 1; j <= tot && i * prime[j] <= n; j++) 
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

inline int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	T = read();
	euler(1000);
	for(int t = 1; t <= T; ++ t)
	{
		n = read(), minn = 1000000000;
		for(int i = 1; i <= n; ++ i)
		{
			a[i] = read(); minn = min(minn, a[i]);
		}
		if(n == 1) 
		{
			std :: cout << "Case " << t << ": 0" << std :: endl;
			continue;
		}

		bool solved = false;
		for(int j = 1; j <= n; ++ j)
		{
			int pre = prime[j];
			int tmp = a[1] % pre;
			bool flag = true;

			for(int i = 2; i <= n; ++ i)
			{
				if(a[i] % pre != tmp)
				{
					flag = false;
					break;
				}
			}

			if(flag == true)
			{	
				//std :: cout << pre << " " << tmp << std :: endl;
				std :: cout << "Case " << t << ": " << pre - tmp << std :: endl;
				solved = true;
				break;
			}
		}
		if(! solved) 
		{
			std :: cout << "Case " << t << ": " << "-1" << std :: endl;
		}
	}
}
 