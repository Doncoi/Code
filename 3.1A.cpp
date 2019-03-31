#include <cstdio>
#include <iostream>
#include <algorithm>
#define  MAXN 100005
#define MAXM 20000005

int n, m, cnt, tot, limits[MAXN * 2];

struct Node {
	int type, ll, rl, father, head;
} node[MAXN * 4];

struct Edge {
	int next, to;
} edge[MAXM];

int find(const int &x) {
	return node[x].father == x ? x : node[x].father = find(node[x].father);
}

bool check(int x, int y) {
	return node[y].ll < node[x].ll && node[x].ll < node[y].rl || node[y].ll < node[x].rl && node[x].rl < node[y].rl; 
}

inline int hash(int l, int r) {
	return l == r ? l + m : l + r >> 1; 
}

inline void addEdge(int x, int y) {
	edge[++ tot].next = node[x].head, node[x].head = tot, edge[tot].to = y;
}


inline int read() {
	char ch = getchar();  int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void segementUnion(int x) {
	if (x == cnt) return;
	if (node[x].ll < node[cnt].ll) node[cnt].ll = node[x].ll;
	if (node[x].rl > node[cnt].rl) node[cnt].rl = node[x].rl;
	node[x].father = cnt;
}

void modify(int l, int r, int x) {
	if (x < l || x > r) return;
	int id = hash(l, r);
	for (int &k = node[id].head, v; v = edge[k].to, k; k = edge[k].next) segementUnion(find(v));
	if (l == r) return;
	int mid = l + r >> 1;
	if (x <= mid) modify(l, mid, x);
	else modify(mid + 1, r, x);
}

void insert(int l, int r, int x) { 
	int id = hash(l, r);
	if (node[x].ll <= l && r <= node[x].rl) {
		addEdge(id, x);
		return;
	}
	
	int mid = l + r >> 1;
	if (node[x].ll <= mid) insert(l, mid, x);
	if (node[x].rl > mid) insert(mid + 1, r, x);
}

int main() {
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; ++i) {
		node[i].type = read(), node[i].ll = read(), node[i].rl = read();
		if (node[i].type & 1) limits[++m] = node[i].ll, limits[++m] = node[i].rl;
	}

	std :: sort(limits + 1, limits + m + 1);
	m = std :: unique(limits + 1, limits + m + 1) - limits - 1;
	for (int i = 1; i <= n; ++i) 
		if (node[i].type & 1) {
			node[i].ll = std :: lower_bound(limits + 1, limits + m + 1, node[i].ll) - limits; 
			node[i].rl = std :: lower_bound(limits + 1, limits + m + 1, node[i].rl) - limits;
		}
		
	for (int i = 1; i <= n; ++i) {
		int x = node[i].ll, y = node[i].rl;
		if (node[i].type & 1) {
			++cnt, node[cnt].ll = x, node[cnt].rl = y, node[cnt].father = cnt;
			modify(1, m, x), modify(1, m, y);
			++ node[cnt].ll, -- node[cnt].rl;
			if (node[cnt].ll <= node[cnt].rl) insert(1, m, cnt); 
			-- node[cnt].ll, ++ node[cnt].rl;
		}
		else {
			x = find(x), y = find(y);
			if (x == y) printf("YES\n");
			else {
				if (check(x, y)) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}