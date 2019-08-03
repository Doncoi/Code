#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 500000 + 5

int n, m, s;
int x, y;
int cnt = 0;
int parent[MAXN][100];

struct Node
{
	int head, dis;
} node[MAXN];

struct Edge
{
	int from, to, next;
} edge[MAXN << 1];

inline void addEdge(int u, int v)
{
	edge[++ cnt].next = node[u].head, node[u].head = cnt;
	edge[cnt].from = u, edge[cnt].to = v;
}

void DFS(int u) {
	for(int e = node[u].head, v; e; e = edge[e].next) {
		if(node[v = edge[e].to].dis || v == s) continue;
		node[v].dis = node[u].dis + 1;
		parent[v][0] = u, DFS(v);
	}
}

int LCA(int x, int y) {
	int i, j;
	if(node[x].dis < node[y].dis) std :: swap(x, y);
	for(i = 1; (1 << i) <= node[x].dis; ++ i); -- i;
	for(j = i; j >= 0; -- j) 
		if(node[x].dis - (1 << j) >= node[y].dis)
			x = parent[x][j];
	if(x == y) return x;

	for(j = i; j >= 0; -- j) 
		if(parent[x][j] != -1 && parent[x][j] != parent[y][j]) 
			x = parent[x][j], y = parent[y][j];
	//printf("All Right\n");
	return parent[x][0];
}

void init() {
	memset(parent, -1, sizeof(parent)); 
	DFS(s);
	for(int j = 1; (1 << j) <= n; j ++) 
		for(int i = 1; i <= n;i ++) 
			if(parent[i][j - 1] != -1)
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
}

inline int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
	while(chr >= '0' && chr <= '9') {res = res * 10 + chr - '0'; chr = getchar();}
	return res * flg;
}

int main()
{
	n = read(), m = read(), s = read();
	for(int i = 1; i <= n - 1; ++ i)
	{
		x = read(), y = read();
		addEdge(x, y), addEdge(y, x);
	}
	init();
	for(int i = 1; i <= m; ++ i)
	{
		x = read(), y = read();
		std :: cout << LCA(x, y) << std :: endl;	
	}
}
