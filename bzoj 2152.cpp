#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 20005

struct Node {
	int x, y, z;

	Node (int x = 0, int y = 0, int z = 0) : x(x), y (y), z(z) {}

	void Rotate() {
		std :: swap(x, y);
		std :: swap(x, z);
	}

	void operator += (const Node &tmp) {
		x += tmp.x;
		y += tmp.y;
		z += tmp.z;
	}
}node[MAXN];

struct Edge {
	int cost, to, next;
} edge[MAXN * 2];

int head[MAXN], cnt;
int n, ans;

int gcd(const int &a, const int &b) {
	return b ? gcd(b, a % b) : a;
}

void addEdge(int from, int to, int cost) {
	edge[++ cnt].to = to, edge[cnt].cost = cost, edge[cnt].next = head[from], head[from] = cnt;
}

void solve(int x, int father) {
	node[x] = Node(1, 0, 0);

	for(int e = head[x]; e; e = edge[e].next) {
		if(edge[e].to == father) {
			continue;
		}

		solve(edge[e].to, x);
		while(edge[e].cost) {
			node[edge[e].to].Rotate();
			edge[e].cost --;
		}

		ans += node[x].x * node[edge[e].to].x;
		ans += node[x].y * node[edge[e].to].z;
		ans += node[x].z * node[edge[e].to].y;

		node[x] += node[edge[e].to];
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++ i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w % 3);
		addEdge(v, u, w % 3);
	}

	solve(1, 0);
	ans = ans * 2 + n;
	int gcdn = gcd(ans, n * n);
	printf("%d/%d\n", ans / gcdn, n * n / gcdn);
}
