#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
const int MAXN = 1005;
const int MAXM = 50005;
const int INF = 0x3f3f3f3f;

int n, m;
int s, t, ans, dis[MAXN];
int cnt = 1, head[MAXN], next[MAXM], to[MAXM], cap[MAXM], cost[MAXM];
bool visisted[MAXN], walk[MAXN];
std :: queue<int> q;

inline void addEdge(int u, int v, int f, int w) {
	next[++ cnt] = head[u], head[u] = cnt, to[cnt] = v, cap[cnt] = f, cost[cnt] = w;
	next[++ cnt] = head[v], head[v] = cnt, to[cnt] = u, cap[cnt] = 0, cost[cnt] = -w;
}

inline void init(int _n, int _m) {
	s = 0, t = _n + 1;
	for(int i = 1; i <= _m; ++ i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		addEdge(u, v, 1, w);
		addEdge(v, u, 1, w);
	}
	addEdge(s, 1, 2, 0);
	addEdge(n, t, 2, 0);
}

bool buildGraph() {
	memset(dis, INF, sizeof(dis));
	memset(walk, false, sizeof(walk));

	q.push(s), dis[s] = 0;
	int u, v, e;
	while(!q.empty()) {
		u = q.front(), q.pop();
		visisted[u] = false;
		for(e = head[u]; e; e = next[e]) {
			if(cap[e] > 0 && dis[u] + cost[e] < dis[v = to[e]]) {
				dis[v] = dis[u] + cost[e];
				if(!visisted[v]) {
					visisted[v] = true;
					q.push(v);
				}
			}
		}
	} 

	return dis[t] < INF;
}

int dfs(int u, int flow) {
	if(u == t) {
		ans += flow * dis[t];
		return flow;
	}	

	walk[u] = true;
	int v, e, res = 0, delta;
	for(e = head[u]; e; e =  next[e]) {
		if(!walk[v = to[e]] && cap[e] > 0 && dis[u] + cost[e] == dis[v]) {
			delta = dfs(v, std :: min(cap[e], flow - res));
			if(delta) {
				cap[e] -= delta, cap[e ^ 1] += delta;
				res += delta; if(res == flow) break;
			}
		}
	}

	return res;
}

int solve() {
	ans = 0;
	while(buildGraph()) {
		dfs(s, INF);
	}

	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	init(n, m);
	printf("%d\n", solve());
	return 0;
}
