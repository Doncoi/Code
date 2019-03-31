#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
#define MAXM 100005
#define INF 0x7fffffff

int n, m, k, s, t, cnt;
int q[MAXN], head, tail, mp[MAXN];  

struct Segment {
	int l, r;
} segment[MAXN];

struct Node {
	int head, pre, pos, dis;
	bool vis;
} node[MAXN];

struct Edge {
	int from, to, next;
	int cap, flow, cost;
} edge[MAXM << 1];

inline int read() {
	char ch = getchar();  int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}	

inline void loop(int &x) {
	if(x == MAXN) x = 1;
	else if(x == 0) x = MAXN - 1;
}

inline int bin(int x) {
	int l = 1, r = m;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(mp[mid] == x) return mid;
		if(x < mp[mid]) r = mid - 1;
		else l = mid + 1;
	}

	return -1;
}

inline void addEdge(int from, int to, int cap, int cost) {
	edge[cnt].from = from, edge[cnt].to = to; 
	edge[cnt].cap = cap, edge[cnt].flow = 0, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt ++;

	edge[cnt].from = to, edge[cnt].to = from;
	edge[cnt].cap = 0, edge[cnt].flow = 0, edge[cnt].cost = -cost;
	edge[cnt].next = node[to].head, node[to].head = cnt ++;
}	

inline void makeGraph() {
	s = 0, t = m + 1;
	addEdge(s, 1, k, 0), addEdge(m, t, k, 0);
	for(int i = 1; i < m; ++ i) 
		addEdge(i, i + 1, INF, 0);
	for(int i = 1; i <= n; ++ i) 
		addEdge(bin(segment[i].l), bin(segment[i].r), 1, -(segment[i].r - segment[i].l));
}

inline bool SPFA() {
	for(int i = 0; i < MAXN; ++ i) 
		node[i].dis = INF, node[i].vis = false;
	head = tail = 1;
	q[tail ++] = s, node[s].vis = true, node[s].dis = 0, node[t].pre = -1;

	while(head != tail) {
		printf("%d - %d All Right\n", head, tail); 
		int u = q[head ++], v, w;  node[u].vis = 0, loop(head);
		for(int e = node[u].head; e; e = edge[e].next) {
			v = edge[e].to, w = edge[e].cost;
			if(edge[e].cap > edge[e].flow && node[v].dis > node[u].dis + w) {
				node[v].dis = node[u].dis + w, node[v].pos = e, node[v].pre = u;
				if(!node[v].vis) {
					node[v].vis = true;
					if(node[v].dis < node[q[head]].dis) -- head, loop(head), q[head] = v;
					else q[tail ++] = v, loop(tail);
				}
			}
		}
	}

	return node[t].pre != -1;
}

int MCMF() {
	int flow = 0, cost = 0;
	while(SPFA()) {
		printf("All Right\n");
		int maxFlow = INF;
		for(int e = t; e != s; e = node[e].pre) 
			maxFlow = std :: min(maxFlow, edge[node[e].pos].cap - edge[node[e].pos].flow); 
		flow += maxFlow, cost += -node[t].dis * maxFlow;
 		printf("ans : %d\n", cost); 
		for(int e = t; e != s; e = node[e].pre)
			edge[node[e].pos].flow += maxFlow, edge[(node[e].pos - 1) ^ 1 + 1].flow += maxFlow;
	}
	
	return cost;
}

int main() {
	n = read(), k = read();
	for(int i = 1; i <= n; ++ i) 
		mp[++ m] = segment[i].l = read(), 
		mp[++ m] = segment[i].r = read();
	std :: sort(mp + 1, mp + 1 + m);
	int p = 0;  mp[++ p] = mp[1];
	for(int i = 2; i <= m; ++ i) 
		if(mp[i] != mp[i - 1]) mp[++ p] = mp[i];
	m = p;

	makeGraph();
	printf("%d\n", MCMF());
}