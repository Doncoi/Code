#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5
#define MAXM 10000 + 5

struct Node
{
	int head;
	int cnt[MAXN];
	bool vis;
} node[MAXN * 2];

struct Edge
{
	int from, to, next;
} edge[MAXM * 4];

struct Pair
{
	int x, y;
} pair[MAXM * 8];

int T, n, m, k, tmp;
int tmpcnt, cnt1, cnt2, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

inline void addEdge(int u, int v)
{
	edge[++ cnt1].from = u, edge[cnt1].to = v;
	edge[cnt1].next = node[u].head, node[u].head = cnt1; 

	edge[++ cnt1].from = v, edge[cnt1].to = u;
	edge[cnt1].next = node[v].head, node[v].head = cnt1;
	node[u].cnt[0] ++, node[v].cnt[0] ++;
}

void DFS(int str, int pre, int cnt)
{
	++ cnt, node[pre].vis = true;
	//std :: cout << "str : " << str << " pre : " << pre << " cnt : " << cnt << std :: endl;

	for(int e = node[pre].head, v; e; e = edge[e].next)
	{
		//std :: cout << e << " " << edge[e].from << "->" << edge[e].to << std :: endl;
		if(node[v = edge[e].to].vis) continue;
		if(cnt == 1)
		{
			DFS(str, v, cnt);
		}
		else if(cnt == 2)
		{
			//std :: cout << "----------" <<str << " pre colmn2 at point : " << v << std :: endl; 
			node[str].cnt[v] ++;
		}
	}
	if(cnt >= 2) return;
}

void init(int x)
{
	for(int i = 1; i <= n; ++ i)
	{
		node[i].vis = false;
	}
	for(int i = 1; i <= n; ++ i)
	{
		node[x].cnt[i] = 0;
	}
}

inline void addPair(int x, int y)
{
	if(x < y) 
	{
		pair[++ cnt2].x = x, pair[cnt2].y = y;
	}
	else if(x > y)
	{
		pair[++ cnt2].x = y, pair[cnt2].y = x;
	}
}

inline bool cmp(const Pair &x, const Pair &y)
{
	if(x.x == y.x) return x.y < y.y;
	else return x.x < y.x;
}

int main()
{
	T = read();
	while(T --)
	{
		n = read(), m = read(), k = read(), cnt1 = cnt2 = 0;
		for(int i = 1; i <= n; ++ i)
		{
			node[i].head = 0;
		}
		for(int i = 1; i <= m; ++ i)
		{
			int x = read(), y = read();
			//std :: cout << "add : " << x << " " << y << std :: endl;
			addEdge(x + 1, y + 1);
		}

		/*
		for(int i = 1; i <= cnt; ++ i)
		{
			std :: cout << "edge " << i << " : " << edge[i].from << " -> " << edge[i].to << " next : " << edge[i].next << std :: endl;
		}
		
		for(int i = 1; i <= n; ++ i)
		{
			std :: cout << "node : " << i << " head : " << node[i].head << " cnt : " << node[i].cnt[0] << std :: endl;
		}
		*/

		ans = tmp = 0, tmpcnt = cnt1;
		for(int i = 1; i <= n; ++ i)
		{
			init(i);
			if(node[i].cnt[0] < k) break;
			DFS(i, i, 0);
			for(int j = 1; j <= n; ++ j)
			{
				if(node[i].cnt[j] >= k)
				{
					addPair(i, j);
					addEdge(i, j);
				}
			}
		}

		/*
		for(int i = 1; i <= n; ++ i)
		{
			std :: cout << "node " << i << " : ";
			for(int j = 1; j <= n; ++ j)
			{
				std :: cout << node[i].cnt[j] << " ";
			}
			std :: cout << std :: endl;
		}
		*/

		for(int i = 1; i <= cnt2; ++ i)
		{
			for(int e = node[pair[i].x].head; e; e = edge[e].next)
			{
				if(edge[e].to == pair[i].y && e <= tmpcnt)
				{
					pair[i].x = pair[i].y = 0;
					break;
				} 
			}
		}
		std :: sort(pair + 1, pair + cnt2 + 1, cmp);
		
		/*
		for(int i = 1; i <= cnt2; ++ i)
		{
			std :: cout << "pair " << i << " : " << pair[i].x << " " << pair[i].y << std :: endl;
		}
		*/
		

		while(++ tmp <= cnt2)
		{	
			if(pair[tmp].x && pair[tmp].y) ++ ans;
			else ++ tmp;
			while(pair[tmp + 1].x == pair[tmp].x && pair[tmp + 1].y == pair[tmp].y)
			{
				++ tmp;
			}
		}

		//std :: cout << "ans : " << ans << std :: endl;
		std :: cout << ans << std :: endl;
	}
}