#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int T, n, ans, maxn;
int a[MAXN];
bool flag[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	T = read();
	while(T --)
	{
		n = read(), ans = 0, maxn = 0;
		memset(flag, false, sizeof(flag));
		for(int i = 1; i <= n; ++ i)
		{
			a[i] = read();
			if(i < 3) continue;
			if(a[i - 2] < a[i - 1] && a[i - 1] > a[i]) 
			{
				flag[i - 1] = true;
				++ ans;
			}
		}
		//std :: cout << ans << std :: endl;

		for(int i = 2; i <= n; ++ i)
		{
			int tmp1 = 0;
			if(a[i - 1] > a[i + 1]) ++ tmp1;
			if(a[i - 1] < a[i + 1]) ++ tmp1	;
			int tmp2 = 0;
			if(flag[i - 1]) ++ tmp2;
			if(flag[i + 1]) ++ tmp2;

			if(tmp1 < tmp2)
			{
				maxn = max(maxn, tmp2 - tmp1);
			}
		}

		std :: cout << ans - maxn << std :: endl;
	}
}
 