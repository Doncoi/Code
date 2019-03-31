#include <cstdio>

const int MAXN = 1e4 + 5;
const int MAXM = 5e4 + 5;

int n, m, timestamp, sum, top, ans;
int d[MAXN], num[MAXN], dfn[MAXN], low[MAXN], belong[MAXN], s[MAXN];
int cnt, head[MAXN], next[MAXM], to[MAXM];
bool visited[MAXN];

inline void addEdge(int u, int v) {
	cnt ++;
	next[cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

inline void Tarjan(int u) {
	int v;
	dfn[u] = low[u] = ++ timestamp;
	s[++ top] = u, visited[u] = true;
	for(int e = head[u]; e; e = next[e]) {
		if(!dfn[v = to[e]]) {
			Tarjan(v);
			if(low[v] < low[u]) {
				low[u] = low[v];
			}
		} else if(visited[v] && low[u] > dfn[v]) {
			low[u] = dfn[v];
		}
	}

	if(dfn[u] == low[u]) {
		int v;
		num[belong[u] = ++ sum] = 1, visited[u] = false; 
		while(v = s[top --], v != u) {
			++ num[belong[v] = sum], visited[v] = false;
		}
	}
}

int main() {
	ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(b, a);
	}
	for(int i = 1; i <= n; i ++) {
		if(!dfn[i]) {
			Tarjan(i);
		}
	}
	
	for(int i = 1; i <= n; ++ i) 
		for(int e = head[i]; e; e = next[e]) {
			//printf("%d %d\n", belong[i], belong[to[e]]);
			if(belong[i] != belong[to[e]]) {
				d[belong[to[e]]] ++;
			}
		}
	
	for(int i = 1; i <= sum; i ++) {
		//printf("%d %d\n", d[i], num[i]); 
		if(!d[i] && !ans) {
			ans = num[i];
			//printf("ans %d\n", ans);
		} else if(!d[i]) {
			ans = -1;
			break;
		}
	}
    
	if(ans == -1) {
		printf("%d", ans = 0);
	} else {
		printf("%d", ans);
	}
}
