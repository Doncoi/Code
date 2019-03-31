#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5
#define MAXM 200000 + 5

int n, m, Q;
int cnt = 0, head[MAXN], to[MAXM], next[MAXM];
int range[MAXN], color[MAXN];
int v[MAXN], d[MAXN], c[MAXN]; 

void DFS(int x, int dis, int clor)
{
	if(range[x] >= dis || dis <= 0)
	{
		return;
	}

	range[x] = dis;
	if(! color[x]) color[x] = clor;

	for(int e = head[x], v = to[e]; e; v = to[e = next[e]])
	{
		DFS(v, dis - 1, clor);
	}
}

inline void addEdge(int u, int v)
{
	to[++ cnt] = v;
	next[cnt] = head[u];
	head[u] = cnt;
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
    for(int i = 1; i <= m; ++ i)
    {
    	int x = read(), y = read();
    	addEdge(x, y), addEdge(y, x);
    }

    Q = read();
    for(int i = 1; i <= Q; ++ i)
    {
    	v[i] = read(), d[i] = read(), c[i] = read();
    }
    for(int i = Q; i >= 1; -- i)
    {
    	DFS(v[i], d[i] + 1, c[i]);
    }
    for(int i = 1; i <= n; ++ i)
    {
    	std :: cout << color[i] << std :: endl;
    }
}
