#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 105

int n, m, ans;

struct Node {
	int x, y;

	Node() {}
	Node(int x, int y) : x(x), y(y) {}

	friend inline Node operator - (const Node &a, const Node &b) {
		return Node(b.x - a.x, b.y - a.y);
	} 

	friend inline int operator * (const Node &a, const Node &b) {
		return (b.x * a.y) - (a.x * b.y);
	}

	friend inline int power(const Node &a, const Node &b) {
		return a.x * b.x + a.y * b.y;
	}
} node;

inline bool check(const Node &a, const Node &b, const Node &c) {
	int dis = (a - c) * (b - c);

	if(dis) return false;
	else return power(a - c, b - c) <= 0;
}

struct Polygon {
	int n;
	Node p[MAXN];

	void init(int x) {
		n = x;
		for(int i = 0; i < n; ++ i) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}

		p[n] = p[0];
		if(Area() < 0) {
			std :: reverse(p, p + n);
		}
		p[n] = p[0];
	}

	inline int Area() const {
		int sum = 0;
		for(int i = 0; i < n; ++ i) {
			sum += p[i] * p[i + 1];
		}
		return sum;
	}

	bool inner(const Node &q) {
		int cnt = 0;
		for(int i = 0; i < n; ++ i) {
			if(check(p[i], p[i + 1], q)) {
				return true;
			}

			int d1 = p[i].y - q.y, d2 = p[i + 1].y - q.y;
			int tmp = (p[i] - q) * (p[i + 1] - q);

			if((tmp >= 0 && d1 < 0 && d2 >= 0) || (tmp <= 0 && d1 >= 0 && d2 < 0)) {
				++ cnt;
			} 
 		}

 		return cnt & 1;
	}
} polygon;

int main() {
	for(int T = 1; ; ++ T) {
		scanf("%d", &n);
		if(!n) {
			break;
		} else {
			scanf("%d", &m);
		}

		polygon.init(n);
		if(T != 1) {
			printf("\n");
		}
		printf("Problem %d:\n", T);

		while(m --) {
			scanf("%d%d", &node.x, &node.y);
			if(polygon.inner(node)) {
				printf("Within\n");
			} else {
				printf("Outside\n");
			}
		}
	}

	return 0;
}
