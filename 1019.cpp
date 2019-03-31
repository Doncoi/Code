#include <cstdio>
#include <string>
#define MAXN 100005

int T, n, m, cnt;

struct Edge {
	int to, next;
} edge[MAXN];

struct Node {
	int head;
} node[MAXN];

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void addEdge(int from, int to) {
	edge[++ cnt].next = node[from].head;
	node[from].head = cnt;
	edge[cnt].to = to;
}

int DFS(int x, int num) {
	int tmp, lmp, flag = 0;
	tmp = node[num].head, lmp = node[x].head;

	while(tmp) {
		flag = 0;
		while(lmp) {
			if(edge[lmp].to == edge[tmp].to) {
				flag = 1; break;
			}
			lmp = edge[lmp].next;
		}

		if(flag == 0) return 0;
		tmp = edge[tmp].next;
	}

	return 1;
}

void init() {
	n = read(), m = read();
	for(int i = 1; i <= m; ++ i) 
		addEdge(read(), read());
}

void solve() {
	int tmp, u, v, flag = 1;
	T = read();
	while(T --) {
		init();
		for(int i = 1; i <= n; ++ i) {
			tmp = node[i].head;
			while(tmp) {
				if(DFS(i, edge[tmp].to))
					tmp = edge[tmp].next;
				else 
					{flag = 0; break;}
			}
			if(flag == 0) break;
		}

		if(flag) printf("Yes\n");
		else printf("No\n");
	}
}

int main() {
	solve();
}
