#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int T, n, k, pos, pre;
long long ans;
int a[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int abs(int x)
{
    if(x < 0) return (x * -1);
    else return x;
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
		n = read(), k = read(), ans = 0;
		for(int i = 1; i <= n; ++ i)
		{
			a[i] = read();
		}
		std :: sort(a + 1, a + n + 1);

		for(int i = 1; i <= n; ++ i)
		{
			if(a[i] == 0 || (a[i] < 0 && a[i + 1] > 0))
			{
				pos = i;
				break;				
			}
		}	

        //std :: cout << pos << std :: endl;

		pre = 1;
		while(pre <= pos)
		{
			ans += abs(a[pre]) * 2;
			pre += k;
		}
		pre = n;
		while(pre > pos)
		{
			ans += a[pre] * 2;
			pre -= k;
		}

        ans -= max(abs(a[1]), a[n]);
		std :: cout << ans << std :: endl;
	}
}