#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

struct Node {
	int head, pos;
	long long dis;
	bool vis;
} node[MAXN << 1];

struct Edge {
	int to, next, cost;
} edge[MAXN << 1];

int n, m, T, cnt, log[MAXN << 1];
long long ans, a[MAXN << 1][18];
std :: set<int> s;

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res  * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

inline long long min(long long a, long long b) {
	return (a < b ? a : b);
}

inline void addEdge(int from, int to, int cost) {
	edge[++ cnt].to = to, edge[cnt].cost = cost;
	edge[cnt].next = node[from].head, node[from].head = cnt;
}

inline void DFS(int u, int pre) {
	a[node[u].pos = ++ T][0] = node[u].dis;
	for(int e = node[u].head, v; e; e = edge[e].next) {
		if((v = edge[e].to) == pre) continue;
		node[v].dis = node[u].dis + edge[e].cost;
		DFS(v, u); a[++ T][0] = node[u].dis;
	}
}

inline long long RMQ(int x, int y) {
	int len = log[y - x + 1];
	return min(a[x][len], a[y - (1 << len) + 1][len]);
}

inline void insert(int x) {
	std :: set<int> :: iterator it = s.insert(x).first;
	ans += a[x][0];
	if(s.size() == 1)  
		return;
	if(it == s.begin()) {
		std :: set<int> :: iterator sec = it; ++ sec;
		ans -= RMQ(*it, *sec);
		return;
	}

	if((++ it) -- == s.end()) {
		std :: set<int> :: iterator pre = it; -- pre;
		ans -= RMQ(*pre, *it);
		return;
	}

	std :: set<int> :: iterator sec = it; ++ sec;
	std :: set<int> :: iterator pre = it; -- pre;
	ans += RMQ(*pre, *sec);
	ans -= RMQ(*it, *sec);
	ans -= RMQ(*pre, *it);
}

inline void erase(int x) {
	std :: set<int> :: iterator it = s.find(x);
	ans -= a[x][0];
	if(s.size() == 1) { s.erase(it); return;}	

	if(it == s.begin()) {
		std :: set<int> :: iterator sec = it; ++ sec;
		ans += RMQ(*it, *sec); s.erase(it); return;
	}

	if((++ it) -- == s.end()) {
		std :: set<int> :: iterator pre = it; -- pre;
		ans += RMQ(*pre, *it); s.erase(it); return;
	}

	std :: set<int> :: iterator sec = it; ++ sec;
	std :: set<int> :: iterator pre = it; -- pre;
	ans -= RMQ(*pre, *sec);
	ans += RMQ(*it, *sec);
	ans += RMQ(*pre, *it);
	s.erase(it);
}

inline long long LCADis() {
	if(s.size() == 0) return 0;
	std :: set<int> :: iterator st = s.begin();
	std :: set<int> :: iterator ed = s.end(); -- ed;
	return RMQ(*st, *ed);
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i) {
		int u = read(), v = read(), w = read();
		addEdge(u, v, w), addEdge(v, u, w);
	}

	DFS(1, 0);
	for(int i = 2; i <= T; ++ i) 
		log[i] = log[i >> 1] + 1;
	for(int j = 1; j <= log[T]; ++ j)
		for(int i = 1; i + (1 << j) - 1 <= T; ++ i) 
			a[i][j] = min(a[i][j - 1], a[i + (1 << j - 1)][j - 1]);

	for(int i = 1; i <= m; ++ i) {
		int x = read();
		if(!node[x].vis) 
			node[x].vis = true, insert(node[x].pos);
		else  
			node[x].vis = false, erase(node[x].pos);
		printf("%lld\n", ans - LCADis() << 1);
	}
}
