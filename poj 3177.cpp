#include <cstdio>
#define MAXN 5005 
#define MAXM 50005

int n, m, du[MAXN], father[MAXN];
int timestamp, from[MAXN], low[MAXN], dfn[MAXN];
int cnt = 1, head[MAXN], next[MAXM * 2], to[MAXM * 2], st[MAXM * 2];
bool cut[MAXM * 2];

int find(int x) {
	return father[x] == x ? father[x] : father[x] = find(father[x]);
} 	

inline void addEdge(int from, int target) {
	next[++ cnt] = head[from], head[from] = cnt, to[cnt] = target, st[cnt] = from;
	next[++ cnt] = head[target], head[target] = cnt, to[cnt] = from, st[cnt] = target; 
}

void Tarjan(int x) {
	int v;
	dfn[x] = low[x] = ++ timestamp;
	for(int e = head[x]; e; e = next[e]) {
		if(e == (from[x] ^ 1)) {
			continue;
		}
		if(!dfn[v = to[e]]) {
			from[v] = e;
			Tarjan(v);
			low[x] = low[x] < low[v] ? low[x] : low[v];
			if(low[v] > dfn[x]) {
				cut[from[v]] = cut[from[v] ^ 1] = true;
			} else {
				low[x] = dfn[v] < low[x] ? dfn[v] : low[x];
			}
		}
	}
}


int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);
		addEdge(u ,v);
	}
	Tarjan(1);
	for(int i = 1; i <= n; i ++) {
		father[i] = i;
	}
	for(int i = 2;i <= cnt; i += 2) {
		if(!cut[i]) {
			father[find(to[i])] = find(st[i]);
		}
	}
	for(int i = 2; i <= cnt; i += 2) {
		if(cut[i]) {
			++ du[find(to[i])];
			++ du[find(st[i])];
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(find(i) == i && du[i] == 1) {
			ans ++;
		}
	}

	printf("%d", (ans + 1) / 2);
}
