#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a, b) (a > b ? a : b)
#define MAXN 6005

int n, root, ans;

struct Node {
	int f[2], parent;
	bool vis;
} node[MAXN];

inline int read() {
	char ch = getchar(); int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void init() {
	for(int i = 0; i < MAXN; ++ i) 
		node[i].parent = node[i].f[0] = node[i].f[1] = 0, node[i].vis = false;
	for(int i = 1; i <= n; ++ i) 
		node[i].f[1] = read();

	root = 0; bool tmp = true;
	for(int i = 1; i < n; ++ i) {
		int u = read(), v = read();
		node[u].parent = v;
		if(root == u || tmp) root = v;
	}
	while(node[root].parent) 
		root = node[root].parent;
}

inline void solve(int u) {
	node[u].vis = true;
	for(int v = 1; v <= n; ++ v) {
		if(node[v].vis || node[v].parent != u) continue;
		solve(v);
		node[u].f[1] += node[v].f[0];
		node[u].f[0] += max(node[v].f[0], node[v].f[1]);
	}
}

int main() {
	while(scanf("%d", &n) && n) {
		init();
		solve(root);
		ans = max(node[root].f[0], node[root].f[1]);
		printf("%d\n", ans);
	}
}
