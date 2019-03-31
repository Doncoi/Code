#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 300 + 5

int n, m, tem;
int maxn, ans, who;
int cnt[MAXN];
bool vis[MAXN];
std :: queue<int> que[MAXN];

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			que[i].push(read());

	for(int i = 1; i <= m; ++ i)
	{
		memset(cnt, 0, sizeof(cnt));
		maxn = 0, who = que[1].front();

		for(int j = 1; j <= n; ++ j)
		{
			int pre = que[j].front();
			while(vis[pre])
			{
				que[j].pop();
				pre = que[j].front();
			}
			++ cnt[pre];

			if(cnt[pre] > maxn)
			{
				maxn = cnt[pre], who = pre;
			}
		}

		vis[who] = true;
		if(i != 1) ans = min(ans, maxn);
		else ans = maxn;
	}

	std :: cout << ans << std :: endl;
}
