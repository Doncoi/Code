#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 505;
const int M = 10005;
int n, m, vt;
int next[M], head[N], cnt, to[M]; 
int mateR[M];
bool visited[N];

inline void addEdge(int u, int v) {
	next[++ cnt] = head[u], head[u] = cnt, to[cnt] = v;
}

bool hungry(int u) {
	for(int e = head[u]; e; e = next[e]) {
		if(!mateR[to[e]]) {
			return mateR[to[e]] = u, true;
		}
	}

	for(int e = head[u]; e; e = next[e]) {
		if(visited[to[e]] == vt) continue;
		visited[to[e]] = vt;
		if(hungry(mateR[to[e]])) {
			return mateR[to[e]] = u, true;
		}
	}

	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i) {
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++ i) {
		++ vt;
		if(hungry(i)) {
			++ ans;
		}
	}

	printf("%d\n", ans);
}
