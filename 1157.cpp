#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 25

int k, w;
int n, m, mod;

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(! isdigit(ch)) {if(ch == '-') flag = -1; ch = getchar();}
	while(isdigit(ch)) {res = res * 10 + ch - '0'; ch = getchar();}
	return res * flag;
}

int max(int x, int y)
{
	return (x > y ? x : y);
}

struct highAccuracy
{
	int len, array[MAXN * 10];
	highAccuracy() {}

	highAccuracy operator = (const int &x)
	{
		if(!x) 
		{
			array[1] = 0, len = 1; 
			return *this;
		}
		len = 0; int tmp = x;
		while(tmp)
		{
			array[++ len] = tmp % 10, tmp /= 10;
		}
		
		return *this;
	}

	highAccuracy operator + (const int &x) const 
	{
		highAccuracy ans; ans = *this;
		
		ans.array[1] += x;
		for(int i = 2; i <= ans.len; ++ i)
		{
			ans.array[i] += ans.array[i - 1] / 10;
			ans.array[i - 1] %= 10;
		}
		while(ans.array[ans.len] > 9)
		{
			ans.array[ans.len + 1] = ans.array[ans.len] / 10;
			ans.array[ans.len] %= 10, ans.len ++;
		}

		return ans;
	}

	highAccuracy operator + (const highAccuracy& x) const
	{
		highAccuracy ans; ans = *this;

		ans.len = max(ans.len, x.len);
		for(int i = 1; i <= ans.len; ++ i)
		{
			ans.array[i] += x.array[i];
		}
		for(int i = 2; i <= ans.len; ++ i)
		{
			ans.array[i] += ans.array[i - 1] / 10;
			ans.array[i - 1] %= 10;
		}
		while(ans.array[ans.len] > 9)
		{
			ans.array[ans.len + 1] = ans.array[ans.len] / 10;
			ans.array[ans.len] %= 10, ans.len ++;
		}

		return ans;
	}

	highAccuracy operator += (const highAccuracy &x)
	{
		*this = *this + x;
		return *this;
	}

	void print() 
	{
		for(int i = len; i; -- i)
		{
			putchar(array[i] + '0');
		}

		return;
	}
} f[2][MAXN * MAXN], ans;


void init()
{
	k = read(), w = read();
	n = w % k ? (w / k + 1) : (w / k);
	mod = w % k, m = (1 << k) - 1; 
}

void solve()
{
	if(n < 2) 
	{
		puts("0");
		return;
	}

	bool pre = 0;
	for(int i = m; i >= 0; -- i)
	{
		f[0][i] = f[0][i + 1] + 1;
	}
	for(int i = 2; i <= n; ++ i)
	{
		pre ^= 1;
		f[pre][1 << mod] = f[pre][m + 1] = 0;
		for(int j = (i == n && mod) ? (1 << mod) - 1 : m; j >= 0; -- j)
		{
			f[pre][j] = f[pre][j + 1] + f[pre ^ 1][j + 1];
		}

		ans += f[pre][1];
	}

	ans.print(), putchar('\n');
}

int main()
{
	init();
	solve();
	return 0;
}
