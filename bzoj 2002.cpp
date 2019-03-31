#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200005

struct Node {
	int ch[2], pre, size, a;
	bool vis;
} node[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

inline void update(int x) {
	node[x].size = node[node[x].ch[0]].size + node[node[x].ch[1]].size + 1;
}

inline void find(int x) {
	if(!node[x].vis) find(node[x].pre);
}

inline bool judge(int x, int y) {
	return node[x].ch[1] == y;
}

inline void rotate(int x) {
	int y = node[x].pre, type = judge(y, x);
	node[y].ch[type] = node[x].ch[!type];
	node[node[y].ch[type]].pre = y, node[x].pre = node[y].pre;
	node[x].ch[!type] = x;

	if(node[y].vis) node[y].vis = false, node[x].vis = true;
	else node[node[x].pre].ch[judge(node[x].pre, y)] = x;
	update(y);
}

inline void splay(int x) {
	find(x);
	while(!node[x].vis) {
		int f = node[x].pre, gf = node[f].pre;
		if(node[f].vis) rotate(x);
		else if( judge(gf, f) == judge(f, x) ) 
			rotate(f), rotate(x);
		else rotate(x), rotate(x);
	}
	update(x);
}

inline int access(int x) {
	int y = 0;
	while(x) {
		splay(x);
		node[node[x].ch[1]].vis = true;
		node[node[x].ch[1] = y].vis = false;
		update(x), x = node[y = x].pre; 
	}
	return y;
}

int main() {
	int n, m;
	while(scanf("%d %d", &n, &m) && (n + m)) {
		for(int i = 1; i <= n; ++ i) node[i].a = read();
		for(int i = 0; i < n + 1; ++ i) 
			node[i].size = 1, node[i].vis = true,
			node[i].pre = node[i].ch[0] = node[i].ch[1] = 0;

		node[0].size = 0;
		for(int i = 1; i <= n; ++ i) 
			node[i].pre = std :: min(i + node[i].a, n + 1);

		m = read();
		while(m --) {
			int op = read();
			if(op == 1) {
				int u = read() + 1;
				access(u), splay(u);
				printf("%d\n", node[node[u].ch[0]].size);
			} else {
				int u = read() + 1, v = read();
				access(u), splay(u);
				node[node[u].ch[0]].pre = node[u].pre, node[u].pre = 0;
				node[node[u].ch[0]].vis = true, node[u].ch[0] = 0;
				update(u);
				node[u].pre = std :: min(n + 1, u + v);
			}
		}
	}
}
