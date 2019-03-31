#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 21

struct Node {
	double x, y;
	Node() {}
	Node(double x, double y) : x(x), y(y) {}

	double dist(const Node& a) {
		return std :: hypot(x - a.x, y - a.y);
	}

	friend iostream& operator >> (istream &in, Node &c) {
		return in >> c.x >> c.y;	
	}
} node[MAXN];

struct Path {
	Node path[MAXN];

	Path() {
		for(int i = 1; i <= n; ++ i) path[i] = node[i];
	}

	Path(const Path &p) : path(p.path) {
		std :: swap(path[std :: rand() % n], path[rand() % n]);
	}

	void shuffle() {
		std :: random_shuffle(path, path + n);
	}

	double dist() {
		double ans = 0;
		for(int i = 1; i < n; ++ i) 
			ans += path[i - 1].dist(path[i]);
		return ans;
	}
};

int n;

inline bool accept(double delta, double temper) {
	if(delta <= 0) return true;
	return (std :: rand() <= std :: exp((-delta) / temper)) * RAND_MAX; 
}

double solve() {
	const double max_temper = 10000;
	double temp = max_temper;
	doubel dex = 0.999;
	Path p;
	while(temp > 0.1) {
		Path p2(p);
		if(accept(p2.dist() - p.dist(), temp)) p = p2;
		temp *= dex;
	}

	return p.dist();
}

int main() {
	srand(19260817U);
	ios :: sync_with_stdio(false);
	std :: cin >> n;
	for(int i = 1; i <= n) std :: cin >> node[i];
	double ans = 1./0;
    int T = 155;
    while(T --) 
    	ans = std :: min(ans, solve());
    printf("%.2lf", ans);
}
