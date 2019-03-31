#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 65
#define MAXM 100005
#define INF 0x7fffffff

int n, m, k, s, t, cnt, ans, pos = 1;
int map[MAXN][MAXN], dis[MAXN][MAXN];
std :: queue<int> q;

struct Node {
	int head, dep, pre;
	int visited;
} node[MAXN >> 1];

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

void init() {
	for(int i = 0; i < MAXN; ++ i)
		node[i].head = -1;
	s = 0, t = MAXN - 1;

	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= m + i - 1; ++ j) {
			dis[i][j] = read();
			pos += 2, map[i][j] = pos;
		}

    for(int i = 1; i <= m; ++ i) {
    	addEdge(s, map[1][i] - 1, 1, 0);
    	addEdge(map[1][i] - 1, map[i][i], 1, dis[1][i]);
    }
    for(int i = 2; i <= n; ++ i)
    	for(int j = 1; j <= m + i - 1; ++ j) {
    		if(j < m + i - 1)
    			addEdge(map[i - 1][j], map[i][j] - 1, 1, 0);
    		if(j > 1)
    			addEdge(map[i - 1][j - 1], map[i][j] - 1, 1, 0);
    		addEdge(map[i][j] - 1, map[i][j], 1, dis[i][j]);
    	}
    for(int i = 1; i < n + m; ++ i)
    	addEdge(map[n][i], t, 1, 0);
}
 
void solve() {
	while(SPFA()) {
		int maxFlow = INF;
		for(int e = t; e != s; e = edge[node[e].pre].from) 
			maxFlow = std :: min(maxFlow, edge[node[e].pre].flow);
		for(int e = t; e != s; e = edge[node[e].pre].from) {
			ans += edge[node[e].pre].cost * maxFlow;
			edge[node[e].pre].flow -= maxFlow, edge[node[e].pre ^ 1].flow += maxFlow;
		}
	}

	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}
