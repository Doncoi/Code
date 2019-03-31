#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

inline void chkmax(int &a, const int &b) {
	a = a < b ? b : a;
}

const int MAXN = 5e4 + 5;
int n, m;

struct point {
	int x, y;
	point() {};
	point(int _x, int _y) : x(_x), y(_y) {}

	friend inline point operator - (const point &lhs, const point &rhs) {
		return point(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	friend inline int operator * (const point &lhs, const point &rhs) {
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	inline int norm() const {
		return x * x + y * y;
	}	
} p[MAXN], q[MAXN];

inline bool cmp(int u, int v) {
	int tmp = (p[u] - p[1]) * (p[v] - p[1]);
	if(tmp != 0) {
		return tmp > 0;
	}
	
	return (p[u] - p[1]).norm() < (p[v] - p[1]).norm();
}

void Graham() {
	int id = 1;
	for(int i = 2; i <= n; ++ i) {
		if(p[i].x < p[id].x || (p[i].x == p[id].x && p[i].y < p[id].y)) {
			id = i;
		} 
	}
	if(id != 1) {
		std :: swap(p[1], p[id]);
	}

	static int per[MAXN];
	for(int i = 1; i <= n; ++ i) {
		per[i] = i; 
	}
	std :: sort(per + 2, per + n + 1, cmp);

	q[++ m] = p[1];
	for(int i = 2; i <= n; ++ i) {
		int j = per[i];
		while(m >= 2 && (p[j] - q[m - 1]) * (q[m] - q[m - 1]) >= 0) {
			-- m;
		}

		q[++ m] = p[j];
	}
}

inline int Area(const point &x, const point &y, const point &z) {
	return (y - x) * (z - x);
}

inline int nxt(int x) {
	if(x == m) {
		return 1;
	} else {
		return x + 1;
	}
}

int solve() {
	if(m == 2) {   //如果队列中只剩下两个点，那么他们一定是最远点对
		return (q[2] - q[1]).norm();
	}

	int res = 0;
	q[m + 1] = q[1];
	for(int i = 1, j = 3; i <= m; ++ i) { //最远点的变化是与枚举边的变化方向相同的，可以顺序美剧对点
		while(nxt(j) != i && Area(q[i], q[i + 1], q[j]) <= Area(q[i], q[i + 1], q[j + 1])) { //查找最远的点
			j = nxt(j);      //使用叉乘来计算距离
		}
		chkmax(res, (q[j] - q[i]).norm());   //更新答案
		chkmax(res, (q[j] - q[i + 1]).norm());
	}

	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	Graham();
	int ans = solve();
	printf("%d\n", ans);

	return 0;
}
