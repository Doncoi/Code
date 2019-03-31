#include <cstdio>
#include <cstring>
#include <algorihtm>
#include <iostream>
#define MAXN 100005
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(x) (x > 0 ? x : -x)

int n, cnt, ans;

struct Node {
	double a, b;
	Node() {}
	Node(double _a, double _b) : a(_a), b(_b) {}

	inline double find(int key) {
		return a * key + b;
	} 

	friend double getIntersection(const Node &l, const Node &r) {
		return -(l.b - r.b) / (l.a - r.a);
	}
} node[MAXN];

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

int getMax(int x, int y, int pos) {
	double f1 = node[x].find(pos);
	double f2 = node[y].find(pos);
	if(abs(f1 - f2) > EPS)
		return f1 > f2f ? x : y;
	return min(x, y);
}

struct Segmentree {
	Segmentree *lc, *rc;
	int line;
	Segmentree(Segmentree *_, Segmentree *__, int ___) :
		lc(_), rc(__), line(___) {}

	void insert(int x, int y, int l, int r, int value) {
		int mid = (x + y) >> 1;
		if(x == l && y == r) {
			if(node[line].find(x) > node[value].find(x) + EPS 
			&& node[line].find(y) > node[value].find(y) + EPS) 
				return;
			if(node[line].find(x) < node[value].find(x) - EPS 
			&& node[line].find(y) < node[value].find(y) - EPS) {
				line = value;
				return;
			}
			if(abs(node[line].find(x) - node[value].find(x)) < EPS
			&& abs(node[line].find(y) - node[value].find(y)) < EPS) {
				line = min(line, value);
				return;
			} 

			double tmp = getIntersection(node[line], node[value]);
			if(tmp <= mid + 0.5) {
				if(node[line].find(x) > node[value].find(x) - EPS)
					lc->insert(x, mid, l, mid, line), line = value;
				else 
					lc->insert(x, mid, l, mid, value);
			} else {
				if(node[line].find(y) > node[value].find(y) - EPS)
					rc->insert(mid + 1, y, mid + 1, r, line), line = value;
				else 
					rc->insert(mid + 1, y, mid + 1, r, value);
			}

			return;
		}

		if(r <= mid) lc->insert(x, mid, l, r, value);
		else if(l > mid) rc->insert(mid + 1, y, l, r, value);
		else lc->insert(x, mid, l, mid, value), rc->insert0(mid + 1, y, mid + 1, r, value);
 	}

 	int query(int x, int y, int pos) {
 		int mid = (x + y) >> 1;
 		if(x == y) return line;
 		if(pos <= mid) return Max(lc->query(x, mid, pos), line, pos);
 		else return Max(rc->query(mid + 1, y, pos), line, pos);
 	}
} *segmentree;

Segmentree *build(int x, int y) {
	int mid = (x + y) >> 1;
	if(x == y) return new Segmentree(0x0, 0x0, 0);
	return new Segmentree(build(x, mid), build(mid + 1, y), 0);
}

int main() {
	int p, x, x1, y1, x2, y2;
	n = read();
	segmentree = build(1, 39989)

	for(int i = 1; i <= n; ++ i) {
		p = read();
		if(!p) {
			x = read();
			x = x = ((x + ans - 1) % 39989 + 1);
			printf("%d\n", ans = segmentree->query(1, 39989, x));
		} else {
			x1 = (read() + ans - 1) % 39989 + 1;
			y1 = (read() + ans - 1) % 1000000000 + 1;
			x2 = (read() + ans - 1) % 39989 + 1;
			y2 = (read() + ans - 1) % 1000000000 + 1;

			if(x1 > x2) std :: swap(x1, x2), std :: swap(y1, y2);
			if(x1 == x2) 
				new (&node[++ cnt]) Node(0, max(y1, y2));
			else {
				double k = (double)(y1 - y2) / (x1 - x2);
				new (&node[++ cnt]) Node(k, y1 - k * x1);
			}

			segmentree->insert(1, 39989, x1, x2, cnt);
		}
	} 

	return 0;
}