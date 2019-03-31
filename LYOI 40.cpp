#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 6

int n, m, ans;
int a[MAXN];
std :: vector<int> g[MAXN + 1][MAXN + 1];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

inline bool DFSCheck(int pos, int cur)
{
	if(pos == n)
	{
		return cur == 1;
	}
	else
	{
		std :: vector<int> &v = g[cur][ a[pos] ];
		for(int i = 0; i < v.size(); ++ i) 
		{
			if(DFSCheck(pos + 1, v[i]))
			{
				return true;
			}
		}

		return false;
	}
}

inline bool check()
{
	return DFSCheck(1, a[0]);
}

void DFS(int cur)
{
	if(cur == n)
	{
		if(check())
		{
			++ ans;
		}
	}
	else
	{
		for(int i = 1; i <= MAXN; ++ i)
		{
			a[cur] = i;
			DFS(cur + 1);
		}
	} 
}

int solve()
{
	ans = 0;
	DFS(0);
	return ans;
}

inline int readLetter()
{
	char chr = getchar();
	while(chr < 'a' || chr > 'f') chr = getchar();
	return chr - 'a' + 1;
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= m; ++ i)
	{
		int x = readLetter(), y = readLetter(), z = readLetter();
		g[x][y].push_back(z);
	}

	std :: cout << solve();
	return 0;
}
