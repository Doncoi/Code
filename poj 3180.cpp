#include <cstdio>
#include <cstring>

const int MAXN = 10005;
const int MAXM = 50005;

int n, m;
int cnt, head[MAXN], next[MAXM], to[MAXM];
int timestamp, dfn[MAXN], low[MAXN];
int s[MAXN], top; 
bool visited[MAXN], inStack[MAXN];
int size[MAXN], sum;

inline void addEdge(int u, int v) {
	cnt ++;
	next[cnt] = head[u];	
	head[u] = cnt;
	to[cnt] = v;
}

void Tarjan(int u) {
	int v;
	dfn[u] = low[u] = ++ timestamp;
	inStack[u] = true;
    s[++ top] = u, visited[u] = true;
    for(int e = head[u]; e; e= next[e]) {
    	if(!dfn[v = to[e]]) {
    		Tarjan(v);
    		low[u] = low[u] < low[v] ? low[u] : low[v];
    	} else if(dfn[v] < low[u] && inStack[v]) {
    		low[u] = dfn[v];
    	}
    }

    if(dfn[u] == low[u]) {	
		int size = 1;
    	while(v = s[top --], v != u) {
    		size ++;
  			inStack[v] = false;
    	}
    	if(size >= 2) {
    		sum ++;
		}
    }
}

int main() {
    sum = cnt = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(v, u);
	}
	for(int i = 1; i <= n; i ++) {
		if(!dfn[i]) {
			Tarjan(i);
		}
	}

	printf("%d\n", sum);
}
