#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 800 + 5
#define MAXM 4000 + 5

struct Node;
struct Edge;

struct Node
{
	Edge *head;
	long long dist;
} node[MAXN * MAXN];

struct Edge
{
	Node *from, *targ;
	long long lenh;
	Edge *next;

	Edge(Node *const u, Node *const v, const long long w) :
		from(u), targ(v), lenh(w), next(u->head) {}
};

int n, m, k;
int a[MAXN];

inline void addEdge(const int u, const int v, const long long w)
{
	node[u].head = new Edge(&node[u], &node[v], w);
}

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

long long dijkstra(const int s, const int t, const int n)
{
	for(int i = 0; i < n; ++ i)
	{
		node[i].dist = LLONG_MAX;
	}
	node[s].dist = 0;

	std :: priority_queue< std :: pair<long long, Node *>,
							std :: vector< std :: pair<long long, Node *> >,
							std :: greater< std :: pair<long long, Node *> > > q;
	q.push(std :: make_pair(0, &node[s]));

	while(! q.empty())
	{
		std :: pair<long long, Node *> p = q.top();
		q.pop();

		Node *u = p.second;
		if(u->dist != p.first) continue;
		if(u->dist > node[t].dist) break;

		for(Edge *e = u->head; e; e = e->next)
		{
			Node *v = e->targ;
			if(v->dist > u->dist + e->lenh)
			{
				v->dist = u->dist + e->lenh;
				q.push(std :: make_pair(v->dist, v));
			}
		}
	} 

	return node[t].dist;
}

int main()
{	
	n = read(), m = read(), k = read();
	k = std :: min(k, n);

	for(int i = 1; i <= n; ++ i)
	{
		a[i] = read();
	}

	int s = 0, t = n + n * k + 1;
	for(int i = 0; i < m; ++ i)
	{
		int u = read(), v = read();
		long long w; std :: cin >> w;

		if(!a[u]) for(int i = 0; i < k; ++ i)
			addEdge(u + n * i, v + n * i, w);
		if(!a[v]) for(int i = 0; i < k; ++ i)
			addEdge(v + n * i, u + n * i, w);

		for(int i = 0; i < k; ++ i)
			if(a[u]) addEdge(u + n * i, v + n * (i + 1), w);
		for(int i = 0; i < k; ++ i)
			if(a[v]) addEdge(v + n * i, u + n * (i + 1), w);
	}

	addEdge(s, 1, 0);
	for(int i = 0; i <= k; ++ i)
		addEdge(n + i * n, t, 0);

	long long ans = dijkstra(s, t, n * (k + 1) + 2 );
	std :: cout << (ans == LLONG_MAX ? -1 : ans) << std :: endl;
	return 0;
} 
