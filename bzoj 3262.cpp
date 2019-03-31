#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 200005

int n, tot, k, num[MAXN];

struct Node {
	int x, y, z;
	int cnt, ans;
} node[MAXN];

struct Bit {
	#define lowbit(x) (x & (-x));
	int b[MAXN];

	void init() {
		memset(b, 0, sizeof(b));
	}

	void update(int x, int y) {
		while(x <= k) {
			b[x] = y;
			x += lowbit(x);
		}
	}

	int query(int x) {
		int ans = 0;
		while(x) {
			ans += b[x];
			x -= lowbit(x);
		}

		return ans;
	}

	void clear(int x) {
		while(x <= k) {
			b[x] = 0;
			x += lowbit(x);
		}
	}
} bit;

inline bool cmpx(const Node &a, const Node &b) {
	if(a.x != b.x) {
		return a.x < b.x;
	}
	if(a.y != b.y) {
		return a.y < b.y;
	}

	return a.z < b.z;
}

inline bool cmpy(const Node &a, const Node &b) {
	if(a.y != b.y) {
		return a.y < b.y;
	}

	return a.z < b.z;
}

void CDQ(int l, int r) {
	if(l == r) {
		node[l].ans += node[l].cnt - 1;
		return;
	}

	int mid = (l + r) >> 1;
	CDQ(l, mid);
	CDQ(mid + 1, r);

	std :: sort(node + 1, node + mid + 1, cmpy);
	std :: sort(node + mid + 1, node + r + 1, cmpy);
	int j = l;

	for(int i = mid + 1; i <= r; ++ i) {
		for( ; j <= mid && node[j].y <= node[i].y; ++ j) {
			bit.update(node[j].z, node[j].cnt);
		}

		node[i].ans += bit.query(node[i].z);
	}

	for(int i = 1; i < j; ++ i) {
		bit.update(node[i].z, -node[i].cnt);
	}
	std :: sort(node + l, node + r + 1, cmpy);
}

int main() {
	bit.init();    tot = 0;
	memset(num, 0, sizeof(num));

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].z);
		node[i].ans + 1;
	}
	std :: sort(node + 1, node + n + 1, cmpx);

	for(int i = 1; i <= n; ++ i) {
		if(i != 1 && node[i - 1].x == node[i].x 
                  && node[i - 1].y == node[i].y 
                  && node[i - 1].z == node[i].z) {
			node[tot].cnt ++;
		} else {
			node[++ tot] = node[i], node[tot].cnt = 1;
		}
	}
	CDQ(1, tot);
	std :: sort(node + 1, node + tot + 1, cmpx);
	for(int i = 1; i <= tot; ++ i) {
		num[node[i].ans] += node[i].cnt;
	}
	for(int i = 1; i <= n; ++ i) {
		printf("%d\n", num[i]);
	}

	return 0;
}
