#include <cmath>
#include <queue>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#define MAXN 20000 + 5
#define MAXM 200000 + 5

struct Node;
struct Edge;

struct Node
{
	Edge *head;
	long long dist;
} node[MAXN];

struct Edge
{
	Node *from, *targ;
	long long lenh;
	Edge *next;

	Edge(Node *u, Node *v, const long long &w) : 
		from(u), targ(v), lenh(w), next(u->head) {}
};

struct ENode
{
	int from, targ;
	long long lenh;
} enode[MAXM];

int n, m, t;
long long ans;

int read()
{
	int res = 0, flag = 1; char ch = getchar();
	while(! isdigit(ch)) {if(ch == '-') flag = -1; ch = getchar();}
	while(isdigit(ch)) {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

inline void addEdge(const int &u, const int &v, const long long &w)
{
	node[u].head = new Edge(&node[u], &node[v], w);
}

void Dijkstra()
{
	std :: priority_queue<std :: pair<long long , Node *>, 
						std :: vector<std :: pair<long long, Node *> >, 
						std :: greater<std :: pair<long long, Node *> > >q;
	q.push(std :: make_pair(0, &node[0]));
	node[0].dist = 0;


	while(! q.empty())
	{
		std :: pair<long long, Node *> p = q.top();
		q.pop();

		if(p.first != p.second->dist)
		{
			continue;
		}

		Node *u = p.second;
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
} 

int main()
{
	t = read();
	while(t --)
	{
		n = read(), m = read(), ans = 0;
		for(int i = 0; i < n; ++ i)
		{
			node[i].dist = LLONG_MAX;
		}
		for(int i = 1; i <= m; ++ i)
		{
			enode[i].from = read() - 1, enode[i].targ = read() - 1;
			scanf("%lld", &enode[i].lenh);
		}

		for(int i = 1; i <= m; ++ i)
		{
			addEdge(enode[i].from, enode[i].targ, enode[i].lenh);
		}
		Dijkstra();
		for(int i = 0; i < n; ++ i)
		{
			ans += node[i].dist, node[i].dist = LLONG_MAX;

			Edge *next, *&e = node[i].head;
			while(e)
			{
				next = e->next, delete e, e = next;
			}
		}

		for(int i = 1; i <= m; ++ i)
		{
			addEdge(enode[i].targ, enode[i].from, enode[i].lenh);
		}
		Dijkstra();
		for(int i = 0; i < n; ++ i)
		{
			ans += node[i].dist;
			Edge *next, *&e = node[i].head;
			while(e)
			{
				next = e->next, delete e, e = next;
			}
		}

		printf("%lld\n", ans);
	}
}
