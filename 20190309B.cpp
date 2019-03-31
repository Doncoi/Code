#include <set>
#include <map>
#include <list>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5
#define INF 1000000000 + 5

long long n, ans, m = INF;
long long c[MAXN];
std :: vector< std :: pair<long long, long long> > edge[MAXN];

void calc(long long now, long long pre)
{
	c[now] = 1;
	std :: vector < std :: pair<long long, long long> > :: iterator X;
	for(X = edge[now].begin(); X != edge[now].end(); ++ X)
	{
		long long to, len;
		std :: pair<long long, long long> tmp(to, len);
		*X = tmp;
		if(to == pre) continue;
		calc(to, now);
		c[now] += c[to];
	}
}

void solve(long long now, long long pre, long long len)
{
	ans += (2 * len * std :: min(c[now], n - c[now]));
	std :: pair<long long, long long> maxn(-1, -1);
	
	std :: vector < std :: pair<long long, long long> > :: iterator X;
	for(X = edge[now].begin(); X != edge[now].end(); ++ X)
	{
		long long to, val;
		std :: pair<long long, long long> tmp(-1, -1);
		*X = tmp;
		if(pre == to) continue;
		maxn = std :: max(maxn, {c[to], val});
	}

	maxn = std :: max(maxn, {n - c[now], len});
	if(2 * maxn.first == n)
	{
		m = std :: min(m, maxn.second);
	}
	else if(maxn.first * 2 < n)
	{
		std :: vector < std :: pair<long long, long long> > :: iterator X;
		for(X = edge[now].begin(); X != edge[now].end(); ++ X)
		{
			m = std :: min(m, X->second);
		}
	}

	for(X = edge[now].begin(); X != edge[now].end(); ++ X)
	{
		long long to, val;
		std :: pair<long long, long long> tmp(to, val);
		*X = tmp;
		if(to == pre) continue;
		solve(to, now, val);
	}

}

int main()
{
	std :: cin >> n;
	for(int i = 1; i <= n - 1; ++ i)
	{
		long long A, B, C;
		std :: cin >> A >> B >> C;
		edge[A].push_back({B, C});
		edge[B].push_back({A, C});
	}

	calc(1, 0);
	solve(1, 0, 0);
	std :: cout << (long long)(ans - m);
} 
