#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 505
#define MAXM (MAXN * MAXN)
#define INF 0x7fffffff

int n, m, s, t, cnt, ans;
int dis[MAXN][MAXN];
std :: queue<int> q;

struct Node {
	int head, dep, pre;
	int visited;
} node[MAXN];

struct Edge {
	int from, to, next;
	int flow, cost;
} edge[MAXM];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void addEdge(int from, int to, int flow, int cost) {
	edge[cnt].from = from, edge[cnt].to = to, edge[cnt].flow = flow, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt ++;
	edge[cnt].from = to, edge[cnt].to = from, edge[cnt].flow = 0, edge[cnt].cost = -cost;
	edge[cnt].next = node[to].head, node[to].head = cnt ++;
}

inline bool SPFA() {
	for(int i = 0; i < MAXN; ++ i) {
		node[i].visited = false;
		node[i].dep = INF, node[i].pre = -1;
	}

	q.push(s);  node[s].visited = true, node[s].dep = 0;
	while(!q.empty()) {
		int u = q.front(), v;  q.pop(); node[u].visited = false;

		for(int e = node[u].head; e != -1; e = edge[e].next) 
			if(edge[e].flow > 0 && node[v = edge[e].to].dep > node[u].dep + edge[e].cost) {
				node[v].dep = node[u].dep + edge[e].cost, node[v].pre = e;
				if(!node[v].visited) node[v].visited = true, q.push(v);
			}
	}
	return node[t].dep < INF;
}

inline void init() {
    s = 0, t = MAXN - 1;
    n = read(), m = read();
    for(int i = 0; i < MAXN; ++ i)
    	node[i].head = -1;
    for(int i = 1; i <= n; ++ i)
    	for(int j = 1; j <= m; ++ j)
    		dis[i][j] = read();

    for(int i = 1; i <= n; ++ i) {
    	addEdge(s, i, 1, 0);
    	for(int j = 1; j <= m; ++ j)
    		addEdge(i, j + n, 1, -dis[i][j]);
    }
    for(int i = 1; i <= m; ++ i)
    	addEdge(i + n, t, 1, 0);
}
 
inline void solve() {
	while(SPFA()) {
		int maxFlow = INF;
		for(int e = t; e != s; e = edge[node[e].pre].from) 
			maxFlow = std :: min(maxFlow, edge[node[e].pre].flow);
		for(int e = t; e != s; e = edge[node[e].pre].from) {
			ans += edge[node[e].pre].cost * maxFlow;
			edge[node[e].pre].flow -= maxFlow, edge[node[e].pre ^ 1].flow += maxFlow;
		}
	}

	printf("%d\n", -ans);
}

int main() {
	init();
	solve();
}
