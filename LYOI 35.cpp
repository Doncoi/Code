#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000000 + 5

int n, m;
long long len[MAXN];
long long l, r, mid, res;

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

long long max(const long long &x, const long long &y)
{
	return (x > y ? x : y);
}

bool check(long long x)
{
	int cnt = 1;
	long long tmp = 0;
	for(int i = 1; i <= n; ++ i)
	{
		if(tmp + len[i] > x)
		{
			tmp = len[i], ++ cnt;
		}
		else 
		{
			tmp += len[i];
		}
	}

	if(cnt <= m)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
	{
		std :: cin >> len[i];
		r += len[i], l = max(l, len[i]);
	}

	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
		{
			res = mid, r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	std :: cout << res << std :: endl;
} 
