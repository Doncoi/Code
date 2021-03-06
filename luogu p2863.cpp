#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3
#define MAXN (10000 + 5) 

using namespace std;

int n, m, ans;
int deep, top, sum;
int color[MAXN], vis[MAXN], cnt[MAXN];
int dfn[MAXN << 1], low[MAXN << 1], stack[MAXN << 1]; 

vector<int> g[MAXN];


void Tarjan(int u)
{
	dfn[u] = low[u] = ++ deep;
	vis[u] = 1, stack[++ top] = u;
	int size = g[u].size();

	for(int i = 0, v; i < size; ++ i)
	{
		if(! dfn[v = g[u][i]])
		{
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else
		{
			if(vis[v])
				low[u] = min(low[u], low[v]);
		}
	}

	if(dfn[u] == low[u])
	{
		color[u] = ++ sum, vis[u] = 0;
		while(stack[top] != u)
		{
			color[stack[top]] = sum;
			vis[stack[top --]] = 0;
		}

		-- top;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	for(int i = 1; i <= n; ++ i)
	{
		if(! dfn[i]) Tarjan(i);
	}

	for(int i = 1; i <= n; ++ i)
	{
		cnt[color[i]] ++;
	}
	for(int i = 1; i <= sum; ++ i)
	{
		if(cnt[i] > 1) ++ ans;
	}

	cout << ans << endl;
}