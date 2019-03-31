#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1005
#define precisoion 0.0001
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(x) (x > 0 ? x : x * -1)

int n;
double d1, d2, c, p;

struct Node {
	double d, p;
} node[MAXN];

inline bool cmp(Node x, Node y) {
	return x.d < y.d;
}

void init() {
	std :: cin >> d1 >> c >> d2 >> p >> n;
	node[1].d = 0, node[1].p = 0;
	node[2].d = d1, node[2].p = 0;

	for(int i = 3; i <= (n + 2); ++ i)
		std :: cin >> node[i].d >> node[i].p;
	std :: sort(node + 1, node + n + 1, cmp);
}

void solve() {
	int j, k = 1; n += 2;
	double ans = 0, x = 0, y = 0, s = c * d2;

	while(k <= n) {
		if(node[k + 1].d - node[k].d > s) 
			{std :: cout << "No Solution\n"; return;}
		for(j = k + 1; node[j].d - node[k].d <= s && j <= n; ++ j)
			if(node[j].p <= node[k].p) {
				y = (node[j].d - node[k].d) / d2;
				if(x < y) ans += node[k].p * (y - x), x = 0;
				else x -= y;
				k = j;
				break;
			}
		if(abs(node[k].d - d1) <= precisoion) {
			printf("%.2lf\n", ans);
			return;
		}
		if(j != k) {
			ans += node[k].p * (c - x);
			x = c - (node[k + 1].d - node[k].d) / d2;
			++ k;
		}
	}
}

int main() {
	init();
	solve();
}
